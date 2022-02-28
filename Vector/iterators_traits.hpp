#ifndef _ITERATOR_TRAITS_HPP_
#define _ITERATOR_TRAITS_HPP_

template <class Iterator>
class iterator_traits
{
};

template <class T>
class iterator_traits<T *>
{
};

template <class T>
class iterator_traits<const T *>
{
};

#endif