#ifndef _MAP_HPP
#define _MAP_HPP
namespace ft
{

#include <functional>
#include "pair.hpp"
#include "node.hpp"
// #include "avl.hpp"
#include "mapIterator.hpp"
#include "reverse_iterator.hpp"
#include "../Vector/enable_if.hpp"
#include "../Vector/is_integral.hpp"

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

        typedef myIter<value_type> iterator;
        typedef myIter<const value_type> const_iterator;

        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef typename ft::reverse_iterator<iterator> reverse_iterator;

    private:

        typedef typename Alloc::template rebind<Node<value_type> >::other node_allocator;
        // typedef typename node_allocator::reference node_reference;
        // typedef typename node_allocator::const_reference node_const_reference;
        typedef Node<value_type> * node_pointer;
        typedef Node<const value_type> * const_node_pointer;
        // typedef typename node_allocator::pointer node_pointer;
        // typedef typename node_allocator::pointer node_pointer;
        // typedef typename node_allocator::const_pointer node_const_pointer;

	private:
		key_compare _ft_compare;
        allocator_type _allocator;
        node_pointer	_root_;
        size_type		_size_;
        node_allocator	_node_allocator;

        value_type *_content(node_pointer node) { return node->content; }
        node_pointer _biggestNode(node_pointer node) const { return !_right(node) ? node : _biggestNode(node->right); }
        node_pointer _smallestNode(node_pointer node) const { return !_left(node) ? node : _smallestNode(node->left); }
        allocator_type _get_allocator() const { return _node_allocator; }
        node_pointer _newNode(pointer p, node_pointer parent)
        {
            node_pointer node = _node_allocator.allocate(1);
            _node_allocator.construct(node, _Node(p, parent));
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
        key_type _key(node_pointer node) const { return node->content->first; }
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
        node_pointer _search(key_type k) const
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
            if (!node)
                return NULL;
            return node->parent;
        }
        node_pointer _rightRotation(node_pointer node)
        {
            node_pointer newParent = _left(node);
            node->left = _right(newParent);
            newParent->right = node;

            newParent->parent = node->parent;
            node->parent = newParent;
            if (_left(node))
                node->left->parent = node;
            return newParent;
        }
        node_pointer _leftRotation(node_pointer node)
        {
            node_pointer newParent = _right(node);
            node->right = _left(newParent);
            newParent->left = node;

            newParent->parent = node->parent;
            node->parent = newParent;
            if (_right(node))
            node->right->parent = node;
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
        node_pointer _insert(node_pointer parent, node_pointer node, pointer p)
        {
            if (node == NULL)
                return _newNode(p, parent);

            if (_ft_compare(_key(node), p->first))
                node->right = _insert(node, node->right, p);
            else
                node->left = _insert(node, node->left, p);
            node = _balance(node);
            return node;
        }
        pair<iterator, bool> _add(key_type first, mapped_type second)
        {
            node_pointer s = _search(first);
            if (s)
                return pair<iterator, bool>(s, false);
            pointer p = _newPair(first, second);
            _root_ = _insert(NULL, _root(), p);
            ++_size_;
            s = _search(first);
            return pair<iterator, bool>(s, true);
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

        template <class InputIterator>
        map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
        : _ft_compare(comp), _allocator(alloc), _root_(NULL), _size_(0)
        {
			for (; first != last; first++)
				operator[](first->first) = first->second;
        }

        map(const map &x)
        {
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

        reverse_iterator rbegin() { return reverse_iterator(end()); }
        const_reverse_iterator rbegin() const { return reverse_iterator(end()); }

        reverse_iterator rend() { return reverse_iterator(begin()); }
        const_reverse_iterator rend() const { return reverse_iterator(begin()); }

        bool empty() const { return _empty(); }

        size_type size() const { return _size(); }

        size_type max_size() const { return _max_size(); }

        mapped_type &operator[](const key_type &k) { return change(k, mapped_type()); }

        pair<iterator, bool> insert(const value_type &val) // TODO:
        {
            return _add(val.first, val.second);
        }
        iterator insert(iterator position, const value_type &val)
        {
            (void)position;
            return insert(val).first;
        }
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last
		, typename enable_if<!is_integral<InputIterator>::value, bool>::type = false)
        {
            for (; first != last; first++)
                operator[](first->first) = first->second;
        }

        void erase(iterator position) { _remove(position->first); }
        size_type erase(const key_type &k) { return _remove(k); }
        void erase(iterator first, iterator last)
        {
            for (; first != last; first++)
                _remove(first->first);
        }

        void swap(map &x);

        void clear() { _clearTree(); }

        key_compare key_comp() const { return _ft_compare; }

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
        value_compare value_comp() const {return value_compare(_ft_compare);}

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
            while(tmp != end())
            {
                if (tmp->first == k)
                    break;
                else if (tmp->first > k )
                    break;
                tmp++;
            }
            return tmp;
        }
        const_iterator lower_bound(const key_type &k) const
        {
            const_iterator tmp = begin();
            while(tmp != end())
            {
                if (tmp->first == k)
                    break;
                else if (tmp->first > k )
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
        { return pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)); }

        pair<iterator, iterator> equal_range(const key_type &k)
        { return pair<iterator, iterator>(lower_bound(k), upper_bound(k)); }

        allocator_type get_allocator() const { return _get_allocator(); }

	};

};
#endif
