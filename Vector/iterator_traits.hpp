#ifndef _ITERATOR_TRAITS_HPP_
#define _ITERATOR_TRAITS_HPP_

template <class Iterator>
class iterator_traits
{
    public:
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::iterator_category    iterator_category;
};

template <class T>
class iterator_traits<T *>
{
    public:
        typedef T                               value_type;
        typedef T&                              reference;
        typedef T*                              pointer;
        typedef size_t                          difference_type;
        typedef std::random_access_iterator_tag iterator_category;
};

template <class T>
class iterator_traits<const T *>
{
    public:
        typedef const T                         value_type;
        typedef const T&                        reference;
        typedef const T*                        pointer;
        typedef size_t                          difference_type;
        typedef std::random_access_iterator_tag iterator_category;
};

#endif