#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_

#include "iterator_traits.hpp"

template <class Iter>
class myIter
{
public:
    typedef typename ft::iterator_traits<Iter>::reference           reference;
    typedef typename ft::iterator_traits<Iter>::pointer             pointer;
    typedef typename ft::iterator_traits<Iter>::value_type          value_type;
    typedef typename ft::iterator_traits<Iter>::difference_type     difference_type;
    typedef typename ft::iterator_traits<Iter>::iterator_category   iterator_category;

private:
    pointer _base;

public:
    myIter(pointer base) : _base(base) {}

    myIter() : _base() {}

    myIter(const myIter &copy) { _base = copy._base; }

    myIter &operator=(const myIter &copy) { _base = copy._base; }
    // --it
    myIter operator--() { _base--; return *this; }
    // it--
    myIter operator--(int) { myIter _tmp = *this; _base--; return _tmp; }
    // ++it
    myIter operator++() { _base++; return *this; }
    // it++
    myIter operator++(int) { myIter _tmp = *this; _base++; return _tmp; }

    bool operator==(const myIter &other) { return (_base == other._base); }

    bool operator!=(const myIter &other) { return !operator==(other); }

    reference operator*() const  { return *_base; }

    pointer operator->() { return _base; }

    myIter operator+(int &a) { return _base + a; }

    myIter operator-(int &a) { return myIter(_base - a); }

    void operator-=(int a) { _base -= a; }

    void operator+=(int a) { _base += a;}

    difference_type operator-(myIter &other) { return _base - other._base; }

    bool operator<(const myIter &other) { return _base < other._base; }

    bool operator>(const myIter &other) { return _base > other._base; }

    bool operator<=(const myIter &other) { return _base <= other._base; }

    bool operator>=(const myIter &other) { return _base >= other._base; }

    reference operator[](int index) { return *(_base + index);}

    pointer base() const {return _base;}
};

template<class T>
myIter<T> operator+(int a,myIter<T> &it) { myIter<T> _tmp = it; return _tmp + a; }

#endif