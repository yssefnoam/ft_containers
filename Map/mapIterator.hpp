#ifndef _ITER_HPP_
#define _ITER_HPP_

#include "iterator_traits.hpp"
#include "avl.hpp"

template <class Iter, class Key, class T>
class myIter
{
public:
    typedef typename ft::iterator_traits<Iter>::reference           reference;
    typedef typename ft::iterator_traits<Iter>::pointer             pointer;
    typedef typename ft::iterator_traits<Iter>::value_type          value_type;
    typedef typename ft::iterator_traits<Iter>::difference_type     difference_type;
    typedef typename ft::iterator_traits<Iter>::iterator_category   iterator_category;
    typedef ft::Tree<const Key, T>::node_pointer                    node_pointer;

private:
    pointer         _avl;
    node_pointer    _current;

    pointer avl() const { return _avl; }
    node_pointer current() const { return _current; }
public:
    myIter(pointer *base)
    : _avl(base)
    , _current = _avl->smallestNode(_avl->root());
    {}

    myIter()
    : _avl(NULL)
    , _current(NULL)
    {}

    template <class T>
    myIter(const myIter<T> &copy)
    : _avl(copy.avl())
    , _current(copy.current())
    {}

    template <class T>
    myIter &operator=(const myIter<T> &copy)
    : _avl(copy.avl())
    , _current(copy.current())
    { return *this; }

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
    bool operator==(const myIter<T> &other) { return (_avl == other.avl() && _current == other.current()); }

    template <class T>
    bool operator!=(const myIter<T> &other) { return !operator==(other); }

    reference operator*() const { return *(operator->()); }

    pointer operator->() { return _current->content; }

};

#endif