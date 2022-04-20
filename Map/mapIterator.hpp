#ifndef _ITER_HPP_
#define _ITER_HPP_

#include "../Vector/iterator_traits.hpp"
#include "avl.hpp"

template <class Key, class Type>
class myIter
{
    typedef	Tree<Key, Type>								tree;	
    typedef tree*													tree_pointer;	
	typedef	typename tree::node_pointer										node_pointer;

public:
    typedef typename tree::reference								reference;
    typedef typename tree::pointer									pointer;
    typedef typename tree::value_type								value_type;
    typedef size_t											difference_type;
    typedef std::bidirectional_iterator_tag							iterator_category;

private:

    node_pointer    _current;
    node_pointer    _previous;
	tree_pointer	_tree;

	node_pointer current() {return _current;}
	node_pointer previous() {return _previous;}
	tree_pointer base() {return _tree;}

    node_pointer next()
    {
        node_pointer right = _tree->right(_current);
        node_pointer parent = _tree->parent(_current);
        if (right)
            return _tree->smallestNode(right);
        else
        {
            while(1)
            {
                parent = _tree->parent(_current);
                if (_tree->)
            }
        }
    }

public:
    myIter(tree_pointer tree)
    {
		_tree = tree;
		_current = _tree->smallestNode(_tree->root());
		_previous = NULL;
	}

    myIter()
    : _current(NULL)
    , _previous(NULL)
    , _tree(NULL)
    {}

    template <class T1, class T2>
    myIter(const myIter<T1,T2> &copy)
    : _previous(copy.previous())
    , _current(copy.current())
    , _tree(copy.base())
    {}

    template <class T1, class T2>
    myIter &operator=(const myIter<T1,T2> &copy)
	{
		_previous = copy.previous();
		_current = copy.current();
		_tree = copy.base();
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

    myIter operator++()
    {
        _previous = _current;
        _current = next();
        return *this;
    }

    // myIter operator++(int)
    // {
    //     myIter _tmp = *this;
    //     _base++;
    //     return _tmp;
    // }

    template <class T1, class T2>
    bool operator==(const myIter<T1,T2> &other) { return (_previous == other.previous() && _current == other.current()); }

    template <class T1, class T2>
    bool operator!=(const myIter<T1,T2> &other) { return !operator==(other); }

    pointer operator->() { return _current->content; }

    reference operator*() const { return *(operator->()); }

};

#endif