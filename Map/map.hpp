#ifndef _MAP_HPP
#define _MAP_HPP

#include <iostream>
#include <functional>
#include "pair.hpp"
#include "make_pair.hpp"
#include "../Vector/reverse_iterator.hpp"
#include "../Vector/enable_if.hpp"
#include "../Vector/is_integral.hpp"
#include "../Vector/equal.hpp"
#include "../Vector/lexicographical_compare.hpp"
#include <__tree>
namespace ft
{
#include "node.hpp"
#include "mapIterator.hpp"

    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
    class map
    {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef size_t size_type;

    private:
        typedef typname std::__tree<value_type, key_compare, allocator_type> _base;

        _base _tree;

    public:
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
            : _tree(comp)
        { }

        template <class InputIterator>
        map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
            : _tree(comp)
        {
        }

        map(const map &x)
        {
        }

        map &operator=(const map &x)
        {
        }

        ~map() { clear(); }

        // iterator begin()
        // {
        //     if (_root())
        //         return iterator(_smallestNode(_root_));
        //     return iterator(NULL);
        // }
        // const_iterator begin() const
        // {
        //     if (_root())
        //         return const_iterator((const_node_pointer)_smallestNode(_root_));
        //     return const_iterator((const_node_pointer)NULL);
        // }

        // iterator end()
        // {
        //     if (_root())
        //     {
        //         iterator it(_biggestNode(_root()));
        //         it++;
        //         return it;
        //     }
        //     return iterator(NULL);
        // }
        // const_iterator end() const { return const_iterator(NULL); }

        // reverse_iterator rbegin() {
        //     return reverse_iterator(end());
        //     }
        // const_reverse_iterator rbegin() const { return reverse_iterator(end()); }

        // reverse_iterator rend() { return reverse_iterator(begin()); }
        // const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

        // bool empty() const { return _empty(); }

        // size_type size() const { return _size(); }

        // size_type max_size() const { return _max_size(); }

        // mapped_type &operator[](const key_type &k) { return _change(k, mapped_type()); }

        // pair<iterator, bool> insert(const value_type &val) { return _add(val.first, val.second); }

        // iterator insert(iterator position, const value_type &val)
        // {
        //     (void)position;
        //     return (insert(val)).first;
        // }
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, bool>::type = false)
        {
            for (const_iterator it = ; ++first)
                insert();
        }

        // void erase(iterator position, typename enable_if<!is_integral<iterator>::value, bool>::type = false) { remove(position->first); }

        // size_type erase(const key_type &k) { return remove(k); }

        // void erase(iterator first, iterator last)
        // {
        //     stack<key_type> s;
        //     while(first != last)
        //     {
        //         s.push(first->first);
        //         ++first;
        //     }
        //     while (s.empty())
        //     {
        //         remove(s.top());
        //         s.pop();
        //     }
        // }

        // void swap(map &x)
        // {
        //     std::swap(x._root_, _root_);
        //     std::swap(x._size_, _size_);
        // }

        // void clear() { _clearTree(); }

        // key_compare key_comp() const { return _ft_compare; }

        // class value_compare
        // {
        //     friend class map;
        // protected:
        //     Compare comp;
        //     value_compare(key_compare c) : comp(c) {}

        // public:
        //     bool operator()(const value_type &x, const value_type &y) const
        //     {
        //         return comp(x.first, y.first);
        //     }
        // };

        // value_compare value_comp() const
        // {
        //     return value_compare(_ft_compare);
        // }

        // iterator find(const key_type &k)
        // {
        //     node_pointer tmp = _search(k);
        //     return tmp ? iterator(tmp) : end();
        // }

        // const_iterator find(const key_type &k) const
        // {
        //     node_pointer tmp = _search(k);
        //     return tmp ? const_iterator(tmp) : end();
        // }

        // size_type count(const key_type &k) const
        // {
        //     if (_search(k))
        //         return 1;
        //     return 0;
        // };

        // iterator lower_bound(const key_type &k)
        // {
        //     iterator tmp = begin();
        //     while (tmp != end())
        //     {
        //         if (tmp->first == k)
        //             break;
        //         else if (tmp->first > k)
        //             break;
        //         tmp++;
        //     }
        //     return tmp;
        // }
        // const_iterator lower_bound(const key_type &k) const
        // {
        //     const_iterator tmp = begin();
        //     while (tmp != end())
        //     {
        //         if (tmp->first == k)
        //             break;
        //         else if (tmp->first > k)
        //             break;
        //         tmp++;
        //     }
        //     return tmp;
        // }

        // iterator upper_bound(const key_type &k)
        // {
        //     iterator it = lower_bound(k);
        //     if (it == end())
        //         return end();
        //     if (!_search(k))
        //         return it;
        //     it++;
        //     return it;
        // }
        // const_iterator upper_bound(const key_type &k) const
        // {
        //     const_iterator it = lower_bound(k);
        //     if (it == end())
        //         return end();
        //     if (!_search(k))
        //         return it;
        //     it++;
        //     return it;
        // }

        // pair<const_iterator, const_iterator> equal_range(const key_type &k) const
        // { return pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)); }

        // pair<iterator, iterator> equal_range(const key_type &k)
        // { return pair<iterator, iterator>(lower_bound(k), upper_bound(k)); }

        // allocator_type get_allocator() const { return _get_allocator(); }
    };
};
// template <class Key, class T, class Compare, class Alloc>
// void swap(ft::map<Key, T, Compare, Alloc> &x, ft::map<Key, T, Compare, Alloc> &y)
// {
//     x.swap(y);
// }

// template <class Key, class T, class Compare, class Alloc>
// bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
// {
//     return lhs.size() == rhs.size() && equal(lhs.begin(), lhs.end(), rhs.begin());
// }

// template <class Key, class T, class Compare, class Alloc>
// bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
// {
//     return !(lhs == rhs);
// }

// template <class Key, class T, class Compare, class Alloc>
// bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
// {
//     return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
// }

// template <class Key, class T, class Compare, class Alloc>
// bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
// {
//     return lhs == rhs || lhs < rhs;
// }

// template <class Key, class T, class Compare, class Alloc>
// bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
// {
//     return lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
// }

// template <class Key, class T, class Compare, class Alloc>
// bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
// {
//     return lhs == rhs || lhs > rhs;
// }
#endif
