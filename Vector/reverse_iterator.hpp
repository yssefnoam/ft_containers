#ifndef _reverse_reverse_iterator_HPP_
#define _reverse_reverse_iterator_HPP_

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
    Iter _iter;

public:
    myReverseIter(Iter base) : _iter(base) {}

    myReverseIter() : _iter() {}

    template<class T>
    myReverseIter(const myReverseIter<T> &copy) { _iter = copy.base(); }

    myReverseIter &operator=(const myReverseIter &copy) { _iter = copy.base(); }
    // --it
    myReverseIter operator--() { _iter++; return *this; }
    // it--
    myReverseIter operator--(int) { myReverseIter _tmp = *this; _iter++; return _tmp; }
    // ++it
    myReverseIter operator++() { _iter--; return *this; }
    // it++
    myReverseIter operator++(int) { myReverseIter _tmp = *this; _iter--; return _tmp; }

    bool operator==(const myReverseIter &other) { return (_iter == other._base); }

    bool operator!=(const myReverseIter &other) { return !operator==(other); }

    reference operator*() const  { return *(_iter.base()); }

    pointer operator->() { return _iter; }

    myReverseIter operator+(int &a) { return _iter + a; }

    myReverseIter operator-(int &a) { return myReverseIter(_iter - a); }

    void operator-=(int a) { _iter -= a; }

    void operator+=(int a) { _iter += a; }

    difference_type operator-(myReverseIter &other) { return _iter - other._base; }

    bool operator<(const myReverseIter &other) { return !(_iter < other.base()); }

    bool operator>(const myReverseIter &other) { return !(_iter > other.base()); }

    bool operator<=(const myReverseIter &other) { return !(_iter <= other.base()); }

    bool operator>=(const myReverseIter &other) { return _iter >= other._base; }

    reference operator[](int index) { return *(_iter + index);}

    Iter base() const {return _iter;}
};

template<class T>
myReverseIter<T> operator+(int a,myReverseIter<T> &it) { myReverseIter<T> _tmp = it; return _tmp + a; }

#endif