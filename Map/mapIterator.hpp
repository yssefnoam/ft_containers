#ifndef _ITER_HPP_
#define _ITER_HPP_

#include "../Vector/iterator_traits.hpp"

template <class T>
class myIter
{

public:
    typedef typename iterator_traits<value_type>::reference reference;
    typedef typename iterator_traits<value_type>::pointer reference;
    typedef typename iterator_traits<value_type>::const_reference reference;
    typedef size_t difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;

private:
    typedef typename Node<value_type>* node_pointer;
    typedef node_pointer* double_node_pointer;

    node_pointer _current;
    double_node_pointer _root;

    node_pointer _right(node_pointer node) const { return node->right; }
    node_pointer _left(node_pointer node) const { return node->left; }
    node_pointer _biggestNode(node_pointer node) { return !_right(node) ? node : _biggestNode(node->right); }
    node_pointer _smallestNode(node_pointer node) { return !_left(node) ? node : _smallestNode(node->left); }
    node_pointer _parent(node_pointer node)
    {
        if (node == _root)
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

    node_pointer current() const { return _current; }
    double_node_pointer base() const { return _root; }

    void backward()
    {
        if (!_current)
        {
            _current = _biggestNode(_root);
            return ;
        }
        node_pointer left = _left(_current);
        node_pointer parent = NULL;
        if (left)
            _current = biggestNode(left);
        else
            while (1)
            {
                while (1)
                {
                    parent = _tree->parent(_current);
                    if (_tree->right(parent) == _current)
                    {
                        _current = parent;
                        break;
                    }
                    _current = parent;
                }
            }
    }
    void forward()
    {
        node_pointer right = _tree->right(_current);
        node_pointer parent = NULL;
        if (right)
            _current = _tree->smallestNode(right);
        else
            while (1)
            {
                parent = _tree->parent(_current);
                if (!parent || _tree->left(parent) == _current)
                {
                    parent = _tree->parent(_current);
                    if (_tree->left(parent) == _current)
                    {
                        _current = parent;
                        break;
                    }
                    _current = parent;
                }
            }
    }

public:
    myIter(tree_pointer tree, bool s)
    {
        _tree = tree;
        if (s)
        {
            _current = _tree->smallestNode(_tree->root());
        }
        else
        {
            _current = NULL;
        }
    }

    template<class K, class P>
    myIter(K tree, P pre, P curr)
    {
        _current = reinterpret_cast<Node<pair<Key, Type> > *>(curr);
        _tree = reinterpret_cast<Tree<Key, Type> *>(tree);
    }

    template<class K, class T>
    operator myIter<K, const T>()
    {
        return myIter<K, T>(_tree, _current);
    }

    // template<class K, class T>
    // operator myIter< K, T>()
    // {
    // }

    myIter()
        : _current(NULL),  _root(NULL)
    {}

    template <class T1, class T2>
    myIter(myIter<T1, T2> &copy)
        : _current(copy.current()), _root(copy.base())
    {}

    template <class T1, class T2>
    myIter &operator=(myIter<T1, T2> &copy)
    {
        _current = copy.current();
        _root = copy.base();
        return *this;
    }

    myIter operator--()
    {
        backward();
        return *this;
    }

    myIter operator--(int)
    {
        myIter _tmp = *this;
        operator--();
        return _tmp;
    }

    myIter operator++()
    {
        forward();
        return *this;
    }

    myIter operator++(int)
    {
        myIter _tmp = *this;
        operator++();
        return _tmp;
    }

    template <class T1, class T2>
    bool operator==(const myIter<T1, T2> &other) const { return (_current == other.current()); }

    template <class T1, class T2>
    bool operator!=(const myIter<T1, T2> &other) const { return !operator==(other); }

    pointer operator->() const { return _current->content; }

    reference operator*() const { return *(operator->()); }
};

#endif