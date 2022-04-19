#ifndef _ITER_HPP_
#define _ITER_HPP_

#include "iterator_traits.hpp"
#include "avl.hpp"

template <class Key, class T>
class myIter
{
public:
    typedef typename ft::iterator_traits<Iter>::reference reference;
    typedef typename ft::iterator_traits<Iter>::pointer pointer;
    typedef typename ft::iterator_traits<Iter>::value_type value_type;
    typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
    typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;

private:
    pointer &_avl;
    ft::Tree<const Key, T> node_pointer = *_current;

public:
    myIter(ft::Tree<const Key, T> &base) : _avl(base) {
        _current = base.smallestNode(base.root());
    }

    myIter()
    : _avl()
    {
    }

    template <class T>
    myIter(const myIter<T> &copy)
    : _avl(copy.avl())
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