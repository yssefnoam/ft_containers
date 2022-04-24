#ifndef _MAP_HPP
#define _MAP_HPP
namespace ft
{

#include <functional>
#include "pair.hpp"
#include "node.hpp"
// #include "avl.hpp"
// #include "mapIterator.hpp"
#include "../Vector/reverse_iterator.hpp"

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

    private:

        typedef typename Alloc::template rebind<Node<value_type> >::other node_allocator;
        typedef typename node_allocator::reference node_reference;
        typedef typename node_allocator::const_reference node_const_reference;
        typedef typename node_allocator::pointer node_pointer;
        typedef typename node_allocator::const_pointer node_const_pointer;

	private:
		key_compare _ft_compare;
        allocator_type _allocator;
        node_pointer	_root_;
        size_type		_size_;
        node_allocator	_node_allocator;

        value_type *_content(node_pointer node) { return node->content; }
        node_pointer _beggestNode(node_pointer node) { return !_right(node) ? node : _beggestNode(node->right); }
        node_pointer _smallestNode(node_pointer node) { return !_left(node) ? node : _smallestNode(node->left); }
        allocator_type _get_allocator() const { return _allocator; }
        node_pointer _newNode(pointer p)
        {
            node_pointer node = _node_allocator.allocate(1);
            _node_allocator.construct(node, _Node(p));
            return node;
        }
        pointer _newPair(key_type k, mapped_type m)
        {
            pointer p = _allocator.allocate(1);
            _allocator.construct(p, value_type(k, m));
            return p;
        }
        bool _empty() const { return _root() ? false : true; }
        node_pointer _left(node_pointer node) const { return node->left; }
        node_pointer _right(node_pointer node) const { return node->right; }
        key_type _key(node_pointer node) { return node->content->first; }
        size_type _size() const { return _size_; }
        node_pointer _root() const { return _root_; }
        size_type _height(node_pointer node) const
        {
            if (!node)
                return 0;
            size_type r = _height(_right(node));
            size_type l = _height(_left(node));
            return (r >= l ? r : l) + 1;
        }
        node_pointer _search(key_type k)
        {
            node_pointer tmp = _root();
            while (tmp)
            {
                if (_key(tmp) == k)
                    return tmp;
                if (_ft_compare(_key(tmp), k))
                    tmp = _right(tmp);
                else
                    tmp = _left(tmp);
            }
            return NULL;
        }
        node_pointer _parent(node_pointer node)
        {
            if (node == _root())
                return NULL;
            node_pointer tmp = _root();
            while (_right(tmp) != node && _left(tmp) != node)
            {
                if (!_ft_compare(_key(tmp), _key(node)))
                    tmp = _left(tmp);
                else
                    tmp = _right(tmp);
            }
            return tmp;
        }
        node_pointer _rightRotation(node_pointer node)
        {
            node_pointer newParent = _left(node);
            node->left = _right(newParent);
            newParent->right = node;
            return newParent;
        }
        node_pointer _leftRotation(node_pointer node)
        {
            node_pointer newParent = _right(node);
            node->right = _left(newParent);
            newParent->left = node;
            return newParent;
        }
        node_pointer _rightRightCase(node_pointer node) { return _leftRotation(node); }
        node_pointer _leftLeftCase(node_pointer node) { return _rightRotation(node); }
        node_pointer _rightLeftCase(node_pointer node)
        {
            node->right = _rightRotation(node->right);
            return _rightRightCase(node);
        }
        node_pointer _leftRightCase(node_pointer node)
        {
            node->left = _leftRotation(node->left);
            return _leftLeftCase(node);
        }
        node_pointer _balance(node_pointer node)
        {
            int rh = _height(node->right);
            int lh = _height(node->left);

            if (rh - lh > 1) // left rotation
            {
                rh = _height(node->right->right);
                lh = _height(node->right->left);
                if (rh - lh >= 0)
                    return _rightRightCase(node);
                else
                    return _rightLeftCase(node);
            }
            else if (rh - lh < -1) // right rotation
            {
                rh = _height(node->left->right);
                lh = _height(node->left->left);
                if (rh - lh <= 0)
                    return _leftLeftCase(node);
                else
                    return _leftRightCase(node);
            }
            return node;
        }
        node_pointer _insert(node_pointer node, pointer p)
        {
            if (node == NULL)
                return _newNode(p);

            if (_ft_compare(_key(node), p->first))
                node->right = _insert(node->right, p);
            else
                node->left = _insert(node->left, p);
            node = _balance(node);
            return node;
        }
        bool _add(key_type first, mapped_type second)
        {
            if (_search(first))
                return false;
            pointer p = _newPair(first, second);
            _root_ = _insert(_root(), p);
            ++_size_;
            return true;
        }
        void _destroyPair(pointer p) { _allocator.destroy(p), _allocator.deallocate(p, 1); }

        void _destroyNode(node_pointer node)
        {
            _destroyPair(node->content);
            node->content = NULL;
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
                    pointer tmp = node->content;
                    node->content = small->content;
                    small->content = tmp;
                    node->right = _remove(_right(node), k);
                    return node;
                }
                else // node with 1 childrens
                {
                    node_pointer child = _right(node) ? _right(node) : _left(node);
                    _destroyNode(node);
                    return child;
                }
            }
            if (_ft_compare(_key(node), k))
                node->right = _remove(node->right, k);
            else
                node->left = _remove(node->left, k);
            node = _balance(node);
            return node;
        }
        bool _remove(key_type k)
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

        mapped_type &change(key_type k, mapped_type m)
        {
            node_pointer node = _search(k);
            if (!node)
                _add(k, m);
            node = _search(k);
            return node->content->second;
        }

    public:
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
        : _ft_compare(comp), _allocator(alloc),_root_(NULL), _size_(0)
        {}

        // template <class InputIterator>
        // map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
        // {
        // }

        // map(const map &x)
        // {
        //     this->~map();
        //     // const map<Key, T>
        //     for (const_iterator it = x.begin(); it != x.end(); it++)
        //         operator[](it->first) = it->second;
        // }

        ~map() { clear(); }

        // map &operator=(const map &x);

        // iterator begin() { return iterator(&avl, true); }
        // const_iterator begin() const { return const_iterator(&avl, true); }

        // iterator end() { return iterator(&avl, false); }
        // const_iterator end() const { return const_iterator(&avl, false); }

        // reverse_iterator rbegin();
        // const_reverse_iterator rbegin() const;

        // reverse_iterator rend();
        // const_reverse_iterator rend() const;

        bool empty() const { return _empty(); }

        size_type size() const { return _size(); }

        size_type max_size() const { return _max_size(); }

        mapped_type &operator[](const key_type &k) { return change(k, mapped_type()); }

        // pair<iterator, bool> insert(const value_type &val);
        // iterator insert(iterator position, const value_type &val);
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last);

        // void erase(iterator position) { avl.remove(position->first); }
        size_type erase(const key_type &k) { return _remove(k); }
        // void erase(iterator first, iterator last);

        void swap(map &x);

        void clear() { _clearTree(); }

        key_compare key_comp() const { return _ft_compare; }

        class value_compare
        {
        protected:
            Compare comp;
            value_compare(key_compare c) : comp(c) {}

        public:
            bool operator()(const value_type &x, const value_type &y) const
            {
                return comp(x.first, y.first);
            }
        };
        // value_compare value_comp() const;

        // iterator find(const key_type &k);
        // const_iterator find(const key_type &k) const;

        size_type count(const key_type &k) const
        {
            if (_search(k))
                return 1;
            return 0;
        };

        // iterator lower_bound(const key_type &k);
        // const_iterator lower_bound(const key_type &k) const;

        // iterator upper_bound(const key_type &k);
        // const_iterator upper_bound(const key_type &k) const;

        // pair<const_iterator, const_iterator> equal_range(const key_type &k) const;
        // pair<iterator, iterator> equal_range(const key_type &k);

        allocator_type get_allocator() const { return _get_allocator(); }
    };

};
#endif
