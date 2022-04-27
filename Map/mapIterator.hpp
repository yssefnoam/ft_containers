#ifndef _ITER_HPP_
#define _ITER_HPP_

#include "../Vector/iterator_traits.hpp"

template <class T>
class myIter
{

public:
    typedef T& reference;
    typedef T* pointer;
    typedef T value_type;
    typedef size_t difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;

private:
    typedef Node<value_type> *node_pointer;
    typedef Node<const value_type> *const_node_pointer;
    typedef Node<value_type>** double_node_pointer;

    node_pointer _current;
    node_pointer _previous;

    node_pointer _right(node_pointer node) const { return node->right; }
    node_pointer _left(node_pointer node) const { return node->left; }
    node_pointer _biggestNode(node_pointer node) const { return !_right(node) ? node : _biggestNode(node->right); }
    node_pointer _smallestNode(node_pointer node) const { return !_left(node) ? node : _smallestNode(node->left); }
    node_pointer _parent(node_pointer node)
    {
        if (!node)
            return NULL;
        return node->parent;
    }

    node_pointer current() const { return _current; }

    void backward()
    {
        if (!_current)
        {
            _current = _previous;
            return ;
        }
        node_pointer left = _left(_current);
        node_pointer parent = NULL;
        if (left)
            _current = _biggestNode(left);
        else
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
    void forward()
    {
        _previous = _current;
        node_pointer right = _right(_current);
        node_pointer parent = NULL;
        if (right)
            _current = _smallestNode(right);
        else
            while (1)
            {
                parent = _parent(_current);
                if (!parent || _left(parent) == _current)
                {
                    _current = parent;
                    break;
                }
                _current = parent;
            }
    }

public:

    myIter(node_pointer curr)
    {
        _current  = curr;
    }

    template<class K>
    operator myIter<const K>()
    {
        const_node_pointer tmp_curr = (const_node_pointer)_current;
        return myIter<const K>(tmp_curr);
    }

    myIter() {}

    template <class T1>
    myIter(myIter<T1> &copy)
        : _current(copy.current())
    {}

    template <class T1>
    myIter &operator=(myIter<T1> &copy)
    {
        _current = copy.current();
        // _droot = copy.base();
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

    // bool operator==(const myIter<T1> o) { return (_droot == o._droot && _current == o._current); }
    template <class T1>
    bool operator==(const myIter<T1> o) { return (_current == o._current); }

    template <class T1>
    bool operator!=(const myIter<T1> o) { return !operator==(o); }

    pointer operator->() const { return _current->content; }

    reference operator*() const { return *(operator->()); }
};

#endif