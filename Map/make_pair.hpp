#ifndef _MAKE_PAIR_HPP
#define _MAKE_PAIR_HPP

#include "pair.hpp"

template <class T1, class T2>
ft::pair<T1, T2> make_pair(T1 x, T2 y)
{
    return (ft::pair<T1, T2>(x, y));
}

#endif
