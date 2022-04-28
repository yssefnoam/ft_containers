#ifndef _map_reverse_iterator_HPP_
#define _map_reverse_iterator_HPP_

#include "../Vector/iterator_traits.hpp"

namespace ft
{
    template <class Iter>
    class map_reverse_iterator
    {
    public:
        typedef typename iterator_traits<Iter>::reference reference;
        typedef typename iterator_traits<Iter>::pointer pointer;
        typedef typename iterator_traits<Iter>::value_type value_type;
        typedef typename iterator_traits<Iter>::difference_type difference_type;
        typedef typename iterator_traits<Iter>::iterator_category iterator_category;
        typedef Iter iterator_type;

    private:
        Iter _iter;

    public:
        map_reverse_iterator(Iter base) : _iter(base) {}

        map_reverse_iterator() : _iter() {}

        template <class T>
        map_reverse_iterator(const map_reverse_iterator<T> &copy) { _iter = copy.base(); }

        map_reverse_iterator &operator=(const map_reverse_iterator &copy)
        {
            _iter = copy.base();
            return *this;
        }
        // --it
        map_reverse_iterator operator--()
        {
            _iter++;
            return *this;
        }
        // it--
        map_reverse_iterator operator--(int)
        {
            map_reverse_iterator _tmp = *this;
            _iter++;
            return _tmp;
        }
        // ++it
        map_reverse_iterator operator++()
        {
            _iter--;
            return *this;
        }
        // it++
        map_reverse_iterator operator++(int)
        {
            map_reverse_iterator _tmp = *this;
            _iter--;
            return _tmp;
        }

        bool operator==(const map_reverse_iterator &other) { return (_iter == other.base()); }

        bool operator!=(const map_reverse_iterator &other) { return !operator==(other); }

        reference operator*() const
        {
            Iter tmp = _iter;
            tmp--;
            return *(tmp);
        }

        pointer operator->() { return &(operator*()); }

        map_reverse_iterator operator+(int a) { return _iter - a; }

        map_reverse_iterator operator-(int a) { return _iter + a; }

        void operator-=(int a) { _iter += a; }

        void operator+=(int a) { _iter -= a; }

        difference_type operator-(map_reverse_iterator &other) { return other.base() - _iter; }

        bool operator<(const map_reverse_iterator &other) { return !(_iter < other.base()); }

        bool operator>(const map_reverse_iterator &other) { return !(_iter > other.base()); }

        bool operator<=(const map_reverse_iterator &other) { return other.base() <= _iter; }

        bool operator>=(const map_reverse_iterator &other) { return other.base() >= _iter; }

        reference operator[](int index) { return *(_iter + index - 1); }

        Iter base() const { return _iter; }
    };

    template <class T>
    map_reverse_iterator<T> operator+(int a, map_reverse_iterator<T> &it)
    {
        map_reverse_iterator<T> _tmp = it;
        return _tmp + a;
    }

};
#endif