#ifndef _reverse_reverse_iterator_HPP_
#define _reverse_reverse_iterator_HPP_


namespace ft
{
#include "iterator_traits.hpp"
    template <class Iter>
    class reverse_iterator
    {
    public:
        typedef typename ft::iterator_traits<Iter>::reference reference;
        typedef typename ft::iterator_traits<Iter>::pointer pointer;
        typedef typename ft::iterator_traits<Iter>::value_type value_type;
        typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
        typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
        typedef Iter iterator_type;

    private:
        Iter _iter;

    public:
        reverse_iterator(Iter base) : _iter(base) {}

        reverse_iterator() : _iter() {}

        template <class T>
        reverse_iterator(const reverse_iterator<T> &copy) { _iter = copy.base(); }

        reverse_iterator &operator=(const reverse_iterator &copy)
        {
            _iter = copy.base();
            return *this;
        }
        // --it
        reverse_iterator operator--()
        {
            _iter++;
            return *this;
        }
        // it--
        reverse_iterator operator--(int)
        {
            reverse_iterator _tmp = *this;
            _iter++;
            return _tmp;
        }
        // ++it
        reverse_iterator operator++()
        {
            _iter--;
            return *this;
        }
        // it++
        reverse_iterator operator++(int)
        {
            reverse_iterator _tmp = *this;
            _iter--;
            return _tmp;
        }

        bool operator==(const reverse_iterator &other) { return (_iter == other.base()); }

        bool operator!=(const reverse_iterator &other) { return !operator==(other); }

        reference operator*() const
        {
            Iter tmp = _iter;
            --tmp;
            return *(tmp);
        }

        pointer operator->() { return &(operator*()); }

        reverse_iterator operator+(int a) { return _iter - a; }

        reverse_iterator operator-(int a) { return _iter + a; }

        void operator-=(int a) { _iter += a; }

        void operator+=(int a) { _iter -= a; }

        difference_type operator-(reverse_iterator &other) { return other.base() - _iter; }

        bool operator<(const reverse_iterator &other) { return !(_iter < other.base()); }

        bool operator>(const reverse_iterator &other) { return !(_iter > other.base()); }

        bool operator<=(const reverse_iterator &other) { return other.base() <= _iter; }

        bool operator>=(const reverse_iterator &other) { return other.base() >= _iter; }

        reference operator[](int index) { return *(_iter + index - 1); }

        Iter base() const { return _iter; }
    };

    template <class T>
    reverse_iterator<T> operator+(int a, reverse_iterator<T> &it)
    {
        reverse_iterator<T> _tmp = it;
        return _tmp + a;
    }

};
#endif