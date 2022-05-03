#ifndef _MAP_HPP
#define _MAP_HPP

#include <iostream>
#include <functional>
#include "pair.hpp"
#include "make_pair.hpp"
#include "../Stack/stack.hpp"
#include "../Vector/reverse_iterator.hpp"
#include "../Vector/enable_if.hpp"
#include "../Vector/is_integral.hpp"
#include "../Vector/equal.hpp"
#include "../Vector/lexicographical_compare.hpp"
#include <sys/time.h>


namespace ft
{
#include "node.hpp"
#include "mapIterator.hpp"

    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
    class map
    {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef size_t size_type;
        typedef Node<value_type> _Node;

        typedef mapIter<value_type> iterator;
        typedef mapIter<const value_type> const_iterator;

        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;

    private:
        typedef typename Alloc::template rebind<Node<value_type> >::other node_allocator;
        typedef Node<value_type> *node_pointer;
        typedef Node<const value_type> *const_node_pointer;

    private:
        key_compare _ft_cmp;
        allocator_type _allocator;
        node_pointer _root_;
        size_type _size_;
        node_allocator _node_allocator;

        value_type *_content(node_pointer node) { return node->content; }
        node_pointer _biggestNode(node_pointer node) const
        {
            while(_right(node))
                node = _right(node);
            return node;
        }
        node_pointer _smallestNode(node_pointer node) const
        {
            while(_left(node))
                node = _left(node);
            return node;
        }
        allocator_type _get_allocator() const { return _node_allocator; }
        node_pointer _newNode(pointer p, node_pointer parent)
        {
            node_pointer node = _node_allocator.allocate(1);
            _node_allocator.construct(node, _Node(p, parent));
            return node;
        }
        pointer _newPair(const key_type &k,const  mapped_type &m)
        {
            pointer p = _allocator.allocate(1);
            _allocator.construct(p, value_type(k, m));
            return p;
        }
        bool _empty() const { return _root() ? false : true; }
        node_pointer _left(const node_pointer &node) const { return node->left; }
        node_pointer _right(const node_pointer &node) const { return node->right; }
        key_type _key(node_pointer &node) const { return node->content->first; }
        size_type _size() const { return _size_; }
        node_pointer _root() const { return _root_; }
        int _height(node_pointer node) const
        {
            return node ? node->height : 0;
        }
        node_pointer _search(const key_type &k) const
        {
            node_pointer tmp = _root();
            while (tmp)
            {
                if (_key(tmp) == k)
                    return tmp;
                if (_ft_cmp(_key(tmp), k))
                    tmp = _right(tmp);
                else
                    tmp = _left(tmp);
            }
            return NULL;
        }
        node_pointer _parent(const node_pointer &node) { return node ? node->parent : NULL; }
        node_pointer _rightRotation(node_pointer &node)
        {
            node_pointer newParent = _left(node);
            node->left = _right(newParent);
            newParent->right = node;

            newParent->parent = node->parent;
            node->parent = newParent;
            if (_left(node))
                node->left->parent = node;

            node->height = 1 + std::max(_height(_right(node)), _height(_left(node)));
            newParent->height = 1 + std::max(_height(_right(newParent)), _height(_left(newParent)));
            return newParent;
        }
        node_pointer _leftRotation(node_pointer &node)
        {
            node_pointer newParent = _right(node);
            node->right = _left(newParent);
            newParent->left = node;

            newParent->parent = node->parent;
            node->parent = newParent;
            if (_right(node))
                node->right->parent = node;
            node->height = 1 + std::max(_height(_right(node)), _height(_left(node)));
            newParent->height = 1 + std::max(_height(_right(newParent)), _height(_left(newParent)));
            return newParent;
        }
        node_pointer _rightRightCase(node_pointer &node) { return _leftRotation(node); }
        node_pointer _leftLeftCase(node_pointer &node) { return _rightRotation(node); }
        node_pointer _rightLeftCase(node_pointer &node)
        {
            node->right = _rightRotation(node->right);
            return _rightRightCase(node);
        }
        node_pointer _leftRightCase(node_pointer &node)
        {
            node->left = _leftRotation(node->left);
            return _leftLeftCase(node);
        }
        node_pointer _balance(node_pointer node)
        {
            int rh = _height(node->right);
            int lh = _height(node->left);
            node->height = 1 + std::max(rh, lh);

            if (rh - lh > 1) // left case
            {
                if (rh - lh >= 0)
                    return _rightRightCase(node);
                else
                    return _rightLeftCase(node);
            }
            else if (rh - lh < -1) // right case
            {
                if (rh - lh <= 0)
                    return _leftLeftCase(node);
                else
                    return _leftRightCase(node);
            }
            return node;
        }
        pair<iterator, bool> _insert(pointer p)
        {
            if (!_root())
            {
                _root_ = _newNode(p, NULL);
                ++_size_;
                return pair<iterator, bool>(iterator(_root()), true);
            }
            node_pointer tmp = _root();
            while (1)
            {
                if (_key(tmp) == p->first)
                    return pair<iterator, bool>(iterator(tmp), false);
                else if (_ft_cmp(_key(tmp), p->first))
                {
                    if (!tmp->right)
                    {
                        tmp->right = _newNode(p, tmp);
                        tmp = _right(tmp);
                        break;
                    }
                    tmp = tmp->right;
                }
                else
                {
                    if (!tmp->left)
                    {
                        tmp->left = _newNode(p, tmp);
                        tmp = _left(tmp);
                        break;
                    }
                    tmp = tmp->left;
                }
            }
            node_pointer balance_me = _parent(tmp);
            while (balance_me)
            {
                if (balance_me != _root())
                {
                    node_pointer parent_balance_me = _parent(balance_me);
                    if (_right(parent_balance_me) == balance_me)
                    {
                        node_pointer ret = balance_me;
                        parent_balance_me->right = _balance(balance_me);
                    }
                    else
                    {
                        node_pointer ret = balance_me;
                        parent_balance_me->left = _balance(balance_me);
                    }
                    balance_me = parent_balance_me;
                }
                else
                {
                    _root_ = _balance(balance_me);
                    break;
                }
            }
            ++_size_;
            return pair<iterator, bool>(iterator(tmp), true);
        }
        pair<iterator, bool> _add(const key_type first,const  mapped_type second)
        {
            const pointer &p = _newPair(first, second);
            pair<iterator, bool> ret = _insert(p);
            if (!ret.second)
                _destroyPair(p);
            return ret;
        }
        void _destroyPair(pointer p)
        {
            _allocator.destroy(p);
            _allocator.deallocate(p, 1);
        }
        void _destroyNode(node_pointer node)
        {
            if (!node)
                return;
            _destroyPair(node->content);
            _node_allocator.destroy(node);
            _node_allocator.deallocate(node, 1);
        }
        node_pointer _remove(node_pointer node, key_type &k)
        {
            if (_key(node) == k)
            {
                if (!_right(node) && !_left(node)) // node with 0 childrens
                {
                    _destroyNode(node);
                    return NULL;
                }
                else if (_right(node) && _left(node)) // node with 2 childrens
                {
                    node_pointer small = _smallestNode(_right(node));
                    pointer content = node->content;
                    node->content = small->content;
                    small->content = content;
                    node->right = _remove(_right(node), k);
                    return node;
                }
                else // node with 1 childrens
                {
                    node_pointer child = _right(node) ? _right(node) : _left(node);
                    child->parent = node->parent;
                    _destroyNode(node);
                    return child;
                }
            }
            if (_ft_cmp(_key(node), k))
                node->right = _remove(node->right, k);
            else
                node->left = _remove(node->left, k);
            node = _balance(node);
            return node;
        }
        bool remove(key_type k)
        {
            if (!_search(k))
                return false;
            _root_ = _remove(_root(), k);
            --_size_;
            return true;
        }
        void _clear(node_pointer node)
        {
            if (node)
            {
                _clear(_left(node));
                _clear(_right(node));
                _destroyNode(node);
            }
        }
        void _clearTree()
        {
            _clear(_root());
            _size_ = 0;
            _root_ = NULL;
        }
        size_type _max_size() const { return _node_allocator.max_size(); }

    public:
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
            : _ft_cmp(comp), _allocator(alloc), _root_(NULL), _size_(0)
        {
        }

        template <class InputIterator>
        map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
            : _ft_cmp(comp), _allocator(alloc), _root_(NULL), _size_(0)
        {
            for (; first != last; first++)
                operator[](first->first) = first->second;
        }

        map(const map &x)
        {
            _root_ = NULL;
            _size_ = 0;
            insert(x.begin(), x.end());
        }

        map &operator=(const map &x)
        {
            this->~map();
            insert(x.begin(), x.end());
            return *this;
        }

        ~map() { clear(); }

        iterator begin()
        {
            if (_root())
                return iterator(_smallestNode(_root_));
            return iterator(NULL);
        }
        const_iterator begin() const
        {
            if (_root())
                return const_iterator((const_node_pointer)_smallestNode(_root_));
            return const_iterator((const_node_pointer)NULL);
        }

        iterator end()
        {
            if (_root())
            {
                iterator it(_biggestNode(_root()));
                it++;
                return it;
            }
            return iterator(NULL);
        }
        const_iterator end() const { return const_iterator(NULL); }

        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }
        const_reverse_iterator rbegin() const { return reverse_iterator(end()); }

        reverse_iterator rend() { return reverse_iterator(begin()); }
        const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

        bool empty() const { return _empty(); }

        size_type size() const { return _size(); }

        size_type max_size() const { return _max_size(); }

        mapped_type &operator[](const key_type &k) { return _add(k, mapped_type()).first->second; }

        pair<iterator, bool> insert(const value_type &val)
        {
            return _add(val.first, val.second);
        }

        iterator insert(iterator position, const value_type &val)
        {
            (void)position;
            return (insert(val)).first;
        }
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, bool>::type = false)
        {
            for (; first != last; first++)
                insert(make_pair(first->first, first->second));
        }

        void erase(iterator position, typename enable_if<!is_integral<iterator>::value, bool>::type = false) { remove(position->first); }

        size_type erase(const key_type &k) { return remove(k); }

        void erase(iterator first, iterator last)
        {
            while (first != last)
                remove((first++)->first);
        }

        void swap(map &x)
        {
            std::swap(x._root_, _root_);
            std::swap(x._size_, _size_);
        }

        void clear() { _clearTree(); }

        key_compare key_comp() const { return _ft_cmp; }

        class value_compare
        {
            friend class map;

        protected:
            Compare comp;
            value_compare(key_compare c) : comp(c) {}

        public:
            bool operator()(const value_type &x, const value_type &y) const
            {
                return comp(x.first, y.first);
            }
        };

        value_compare value_comp() const
        {
            return value_compare(_ft_cmp);
        }

        iterator find(const key_type &k)
        {
            node_pointer tmp = _search(k);
            return tmp ? iterator(tmp) : end();
        }

        const_iterator find(const key_type &k) const
        {
            node_pointer tmp = _search(k);
            return tmp ? const_iterator(tmp) : end();
        }

        size_type count(const key_type &k) const
        {
            if (_search(k))
                return 1;
            return 0;
        };

        iterator lower_bound(const key_type &k)
        {
            iterator tmp = begin();
            while (tmp != end())
            {
                if (tmp->first == k)
                    break;
                else if (tmp->first > k)
                    break;
                tmp++;
            }
            return tmp;
        }
        const_iterator lower_bound(const key_type &k) const
        {
            const_iterator tmp = begin();
            while (tmp != end())
            {
                if (tmp->first == k)
                    break;
                else if (tmp->first > k)
                    break;
                tmp++;
            }
            return tmp;
        }

        iterator upper_bound(const key_type &k)
        {
            iterator it = lower_bound(k);
            if (it == end())
                return end();
            if (!_search(k))
                return it;
            it++;
            return it;
        }
        const_iterator upper_bound(const key_type &k) const
        {
            const_iterator it = lower_bound(k);
            if (it == end())
                return end();
            if (!_search(k))
                return it;
            it++;
            return it;
        }

        pair<const_iterator, const_iterator> equal_range(const key_type &k) const
        {
            return pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
        }

        pair<iterator, iterator> equal_range(const key_type &k)
        {
            return pair<iterator, iterator>(lower_bound(k), upper_bound(k));
        }

        allocator_type get_allocator() const { return _get_allocator(); }
    };
};
template <class Key, class T, class Compare, class Alloc>
void swap(ft::map<Key, T, Compare, Alloc> &x, ft::map<Key, T, Compare, Alloc> &y)
{
    x.swap(y);
}

template <class Key, class T, class Compare, class Alloc>
bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
    return lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
    return !(lhs == rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
    return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
    return lhs == rhs || lhs < rhs;
}

template <class Key, class T, class Compare, class Alloc>
bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
    return lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
{
    return lhs == rhs || lhs > rhs;
}
#endif
