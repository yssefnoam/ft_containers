#ifndef _REVERSE_reverse_iterator_HPP_
#define _REVERSE_reverse_iterator_HPP_

#include "iterator_traits.hpp"

template <class Iter>
class myReverseIter
{
public:
    typedef typename ft::iterator_traits<Iter>::reference           reference;
    typedef typename ft::iterator_traits<Iter>::pointer             pointer;
    typedef typename ft::iterator_traits<Iter>::value_type          value_type;
    typedef typename ft::iterator_traits<Iter>::difference_type     difference_type;
    typedef typename ft::iterator_traits<Iter>::iterator_category   iterator_category;

private:
    Iter _base;

public:
    myReverseIter(Iter base) : _base(base) {}

    myReverseIter() : _base() {}

    myReverseIter(const myReverseIter &copy) { _base = copy._base; }

    myReverseIter &operator=(const myReverseIter &copy) { _base = copy._base; }
    // --it
    myReverseIter operator--() { _base++; return *this; }
    // it--
    myReverseIter operator--(int) { myReverseIter _tmp = *this; _base++; return _tmp; }
    // ++it
    myReverseIter operator++() { _base--; return *this; }
    // it++
    myReverseIter operator++(int) { myReverseIter _tmp = *this; _base--; return _tmp; }

    bool operator==(const myReverseIter &other) { return (_base == other._base); }

    bool operator!=(const myReverseIter &other) { return !operator==(other); }

    reference operator*() const  { return *_base; }

    pointer operator->() { return _base; }

    myReverseIter operator+(int &a) { return _base + a; }

    myReverseIter operator-(int &a) { return myReverseIter(_base - a); }

    void operator-=(int a) { _base -= a; }

    void operator+=(int a) { _base += a;}

    difference_type operator-(myReverseIter &other) { return _base - other._base; }

    bool operator<(const myReverseIter &other) { return _base < other._base; }

    bool operator>(const myReverseIter &other) { return _base > other._base; }

    bool operator<=(const myReverseIter &other) { return _base <= other._base; }

    bool operator>=(const myReverseIter &other) { return _base >= other._base; }

    reference operator[](int index) { return *(_base + index);}

    pointer base() const {return _base;}
};

template<class T>
myReverseIter<T> operator+(int a,myReverseIter<T> &it) { myReverseIter<T> _tmp = it; return _tmp + a; }

#endif