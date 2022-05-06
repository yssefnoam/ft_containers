#ifndef _ITER_HPP_
#define _ITER_HPP_

#include "../Vector/iterator_traits.hpp"

template <class T>
class mapIter
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
    node_pointer _biggestNode(node_pointer node) const
    { return !_right(node) ? node : _biggestNode(node->right); }
    node_pointer _smallestNode(node_pointer node) const
    { return !_left(node) ? node : _smallestNode(node->left); }
    node_pointer _parent(node_pointer node)
    {
        if (!node)
            return NULL;
        return node->parent;
    }


    void backward()
    {
        if (!_current)
        {
            _current = _previous;
            return ;
        }
        node_pointer left = _left(_current);
        if (left)
            _current = _biggestNode(left);
        else
            while (1)
            {
                node_pointer parent = _parent(_current);
                if (!parent || _right(parent) == _current)
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
        if (right)
            _current = _smallestNode(right);
        else
            while (1)
            {
                node_pointer parent = _parent(_current);
                if (!parent || _left(parent) == _current)
                {
                    _current = parent;
                    break;
                }
                _current = parent;
            }
    }

public:
    node_pointer current() const { return _current; }
    node_pointer previous() const { return _current; }

    mapIter(node_pointer curr) { _current = curr; }

    template<class K>
    operator mapIter<const K>()
    {
        const_node_pointer tmp_curr = (const_node_pointer)_current;
        return mapIter<const K>(tmp_curr);
    }

    mapIter() {}

    template <class T1>
    mapIter(const mapIter<T1> &copy)
        : _current((Node<value_type> *)copy.current())
        , _previous((Node<value_type> *)copy.previous())
    {}

    template <class T1>
    mapIter &operator=(mapIter<T1> &copy)
    {
        _current = (Node<value_type> *)copy.current();
        _previous = (Node<value_type> *)copy.previous();
        return *this;
    }

    mapIter operator--()
    {
        backward();
        return *this;
    }

    mapIter operator--(int)
    {
        mapIter _tmp = *this;
        operator--();
        return _tmp;
    }

    mapIter operator++()
    {
        forward();
        return *this;
    }

    mapIter operator++(int)
    {
        mapIter _tmp = *this;
        operator++();
        return _tmp;
    }

    pointer operator->() const { return _current->content; }

    reference operator*() const { return *(operator->()); }

    bool operator==(const mapIter lhs) { return _current == lhs._current; }

    bool operator!=(const mapIter lhs) { return _current != lhs._current; }
};

#endif