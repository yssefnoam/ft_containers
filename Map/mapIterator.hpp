#ifndef _ITER_HPP_
#define _ITER_HPP_

#include "../Vector/iterator_traits.hpp"

template <class T, class Compare>
class myIter
{

public:
    typedef T& reference;
    typedef T* pointer;
    typedef T value_type;
    typedef size_t difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;

private:
    typedef Node<value_type>* node_pointer;
    typedef node_pointer* double_node_pointer;
    typedef Compare key_compare;

    node_pointer _current;
    node_pointer _root;
    double_node_pointer _droot;
    key_compare _ft_compare;

    node_pointer _right(node_pointer node) const { return node->right; }
    node_pointer _left(node_pointer node) const { return node->left; }
    node_pointer _biggestNode(node_pointer node) { return !_right(node) ? node : _biggestNode(node->right); }
    node_pointer _smallestNode(node_pointer node) { return !_left(node) ? node : _smallestNode(node->left); }
    node_pointer _parent(node_pointer node)
    {
        if (node == _root)
            return NULL;
        node_pointer tmp = _root;
        while (_right(tmp) != node && _left(tmp) != node)
        {
            if (_ft_compare(tmp->content->first, node->content->first))
                tmp = _right(tmp);
            else
                tmp = _left(tmp);
        }
        return tmp;
    }

    node_pointer current() const { return _current; }
    double_node_pointer base() const { return _droot; }

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
            _current = _biggestNode(left);
        else
            while (1)
            {
                while (1)
                {
                    parent = _parent(_current);
                    if (_right(parent) == _current)
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
        node_pointer right = _right(_current);
        node_pointer parent = NULL;
        if (right)
            _current = _smallestNode(right);
        else
            while (1)
            {
        std::cout << "forward" << std::endl;
                parent = _parent(_current);
                if (!parent || _left(parent) == _current)
                {
                    parent = _parent(_current);
                    if (_left(parent) == _current)
                    {
                        _current = parent;
                        break;
                    }
                    _current = parent;
                }
            }
    }

public:
    myIter(double_node_pointer rt, node_pointer  curr, const key_compare &comp = key_compare())
    {
        _droot = rt;
        _current  = curr;
        _ft_compare = comp;
    }

    // template<class K, class P>
    // myIter(K tree, P pre, P curr)
    // {
    //     _current = reinterpret_cast<Node<pair<Key, Type> > *>(curr);
    //     _tree = reinterpret_cast<Tree<Key, Type> *>(tree);
    // }

    // template<class K, class T>
    // operator myIter<K, const T>()
    // {
    //     return myIter<K, T>(_tree, _current);
    // }

    // template<class K, class T>
    // operator myIter< K, T>()
    // {
    // }

    myIter() {}

    template <class T1, class T2>
    myIter(myIter<T1, T2> &copy)
        : _current(copy.current()), _droot(copy.base())
    {}

    template <class T1, class T2>
    myIter &operator=(myIter<T1, T2> &copy)
    {
        _current = copy.current();
        _droot = copy.base();
        return *this;
    }

    myIter operator--()
    {
        _root = *_droot;
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
        _root = *_droot;
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
    bool operator==(const myIter<T1, T2> &o) const { return (_root == o.base() && _current == o.current()); }

    template <class T1, class T2>
    bool operator!=(const myIter<T1, T2> &other) const { return !operator==(other); }

    pointer operator->() const { return _current->content; }

    reference operator*() const { return *(operator->()); }
};

#endif