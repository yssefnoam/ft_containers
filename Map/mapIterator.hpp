#ifndef _ITER_HPP_
#define _ITER_HPP_

#include "iterator_traits.hpp"

template <class Iter>
class myIter
{
public:
    typedef typename ft::iterator_traits<Iter>::reference reference;
    typedef typename ft::iterator_traits<Iter>::pointer pointer;
    typedef typename ft::iterator_traits<Iter>::value_type value_type;
    typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
    typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;

private:
    pointer _base;

    node_pointer smallestSuccessor(pointer node) { return !left(node) ? node : smallestSuccessor(node->left); }

    pointer forwordNode()
    {
    }

    pointer backwordNode()
    {
    }

public:
    myIter(pointer base)
    : _base(base)
    {
    }

    myIter()
    : _base()
    {
    }

    template <class T>
    myIter(const myIter<T> &copy)
    : _base(copy.base())
    {
    }

    template <class T>
    myIter &operator=(const myIter<T> &copy)
    {
        _base = copy.base();
        return *this;
    }
    myIter operator--()
    {
        _base--;
        return *this;
    }

    myIter operator--(int)
    {
        myIter _tmp = *this;
        _base--;
        return _tmp;
    }

    myIter operator++()
    {
        _base++;
        return *this;
    }

    myIter operator++(int)
    {
        myIter _tmp = *this;
        _base++;
        return _tmp;
    }

    template <class T>
    bool operator==(const myIter<T> &other) { return (_base == other.base()); }

    template <class T>
    bool operator!=(const myIter<T> &other) { return !operator==(other); }

    reference operator*() const { return *_base; }

    pointer operator->() { return _base; }

    pointer base() const { return _base; }
};

#endif