#ifndef _ITER_HPP_
#define _ITER_HPP_

#include "../Vector/iterator_traits.hpp"
#include "avl.hpp"

template <class Iter>
class myIter
{
public:
    typedef typename ft::iterator_traits<Iter>::reference			reference;
    typedef typename ft::iterator_traits<Iter>::pointer				pointer;
    typedef typename ft::iterator_traits<Iter>::value_type			value_type;
    typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
    typedef std::bidirectional_iterator_tag							iterator_category;

    typedef void*													node_pointer;

private:

    node_pointer    _current;
    node_pointer    _previous;

public:
    myIter(node_pointer c, node_pointer p)
    : _current(c)
    , _previous(p)
    {}

    myIter()
    : _previous(NULL)
    , _current(NULL)
    {}

	node_pointer current() {return _current;}
	node_pointer previous() {return _previous;}

    template <class T>
    myIter(const myIter<T> &copy)
    : _previous(copy.previous())
    , _current(copy.current())
    {}

    template <class T>
    myIter &operator=(const myIter<T> &copy)
	{
		_previous = copy.previous();
		_current = copy.current();
		return *this;
	}

	// myIter operator--()
    // {
    //     _base--;
    //     return *this;
    // }

    // myIter operator--(int)
    // {
    //     myIter _tmp = *this;
    //     _base--;
    //     return _tmp;
    // }

    // myIter operator++()
    // {
    //     _base++;
    //     return *this;
    // }

    // myIter operator++(int)
    // {
    //     myIter _tmp = *this;
    //     _base++;
    //     return _tmp;
    // }

    template <class T>
    bool operator==(const myIter<T> &other) { return (_previous == other.previous() && _current == other.current()); }

    template <class T>
    bool operator!=(const myIter<T> &other) { return !operator==(other); }

    reference operator*() const { return *(operator->()); }

    pointer operator->() { return (*_current).content; }

};

#endif