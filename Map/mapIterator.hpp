#ifndef _ITER_HPP_
#define _ITER_HPP_

#include "avl.hpp"
#include "../Vector/iterator_traits.hpp"

template <class Key, class Type>
class myIter
{
    typedef Tree<Key, Type> tree;
    typedef typename iterator_traits<tree*>::pointer tree_pointer;
    typedef typename tree::node_pointer node_pointer;
    typedef typename tree::node_const_pointer node_const_pointer;

public:
    typedef typename tree::reference reference;
    typedef typename tree::pointer pointer;
    typedef typename tree::value_type value_type;
    typedef size_t difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;

private:
    node_pointer _current;
    node_pointer _previous;
    tree_pointer _tree;

    node_pointer current() const { return _current; }
    node_pointer previous() const { return _previous; }
    tree_pointer base() const { return _tree; }

    void backward()
    {
        if (!_current)
        {
            _current =_tree->beggestNode(_tree->root());
            return ;
        }
        node_pointer left = _tree->left(_current);
        node_pointer parent = NULL;
        if (left)
            _current = _tree->beggestNode(left);
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
            _previous = NULL;
        }
        else
        {
            _previous = _tree->beggestNode(_tree->root());
            _current = NULL;
        }
    }

    template<class K, class P>
    myIter(K tree, P pre, P curr)
    {
        _current = reinterpret_cast<Node<pair<Key, Type> > *>(curr);
        _previous = reinterpret_cast<Node<pair<Key, Type> > *>(pre);
        _tree = reinterpret_cast<Tree<Key, Type> *>(tree);
    }

    template<class K, class T>
    operator myIter<K, const T>()
    {
        return myIter<K, T>(_tree, _previous, _current);
    }

    // template<class K, class T>
    // operator myIter< K, T>()
    // {
    //     return myIter< K, T>(_tree, _previous, _current);
    // }

    myIter()
        : _current(NULL), _previous(NULL), _tree(NULL)
    {}

    template <class T1, class T2>
    myIter(myIter<T1, T2> &copy)
        : _current(copy.current()), _previous(copy.previous()), _tree(copy.base())
    {}

    template <class T1, class T2>
    myIter &operator=(myIter<T1, T2> &copy)
    {
        _previous = copy.previous();
        _current = copy.current();
        _tree = copy.base();
        return *this;
    }

    myIter operator--()
    {
        // _previous = _current;
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
        // _previous = _current;
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
    bool operator==(const myIter<T1, T2> &other) const { return (_previous == other.previous() && _current == other.current()); }

    template <class T1, class T2>
    bool operator!=(const myIter<T1, T2> &other) const { return !operator==(other); }

    pointer operator->() const { return _current->content; }

    reference operator*() const { return *(operator->()); }
};

#endif