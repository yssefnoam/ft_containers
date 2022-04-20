#ifndef _MAP_HPP
#define _MAP_HPP
namespace ft
{
#include <functional>
#include "pair.hpp"
#include "node.hpp"
#include "avl.hpp"
#include "mapIterator.hpp"

    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class map
	{
		typedef Key key_type;
		typedef T mapped_type;
		typedef pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		// TODO:
        typedef myIter<value_type> iterator;
        // typedef	myiterator<const_node>					const_iterator;
		// typedef	myRiterator<node>						reverse_iterator;
		// typedef	myRiterator<const_node>					const_reverse_iterator;
		typedef size_t size_type;
        typedef Tree<Key, T, key_compare, allocator_type>   _Tree;
	private:
		_Tree avl;

		key_compare _ft_compare;
		allocator_type _allocator;

	public:

		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
        : _ft_compare(comp)
        , _allocator(alloc)
		{}

		// template <class InputIterator>
		// map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
        // {
        // }

        // map(const map &x);

        ~map()
        {
            avl.clearTree();
        }

        // map &operator=(const map &x);

        iterator begin()
        {
            iterator it(&avl);
            return it;
        }
        // const_iterator begin() const;

		// iterator end();
		// const_iterator end() const;

		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;

		// reverse_iterator rend();
		// const_reverse_iterator rend() const;

        bool empty() const { return avl.empty(); }

        size_type size() const { return avl.size(); }

        size_type max_size() const { return avl.max_size(); }

		mapped_type &operator[](const key_type &k) { return avl.change(k, mapped_type()); }

		// pair<iterator, bool> insert(const value_type &val);
		// iterator insert(iterator position, const value_type &val);
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last);

		// void erase(iterator position);
		size_type erase(const key_type &k);
		// void erase(iterator first, iterator last);

		void swap(map &x);

		void clear();

		key_compare key_comp() const { return _ft_compare; }

		class value_compare
		{
		protected:
			Compare comp;
			value_compare(key_compare c) : comp(c) {}

		public:
			bool operator()(const value_type &x, const value_type &y) const
			{
				return comp(x.first, y.first);
			}
		};
		// value_compare value_comp() const;

		// iterator find(const key_type &k);
		// const_iterator find(const key_type &k) const;

        size_type count(const key_type &k) const
        {
            if (avl.search(k))
                return 1;
            return 0;
        };

        // iterator lower_bound(const key_type &k);
		// const_iterator lower_bound(const key_type &k) const;

		// iterator upper_bound(const key_type &k);
		// const_iterator upper_bound(const key_type &k) const;

		// pair<const_iterator, const_iterator> equal_range(const key_type &k) const;
		// pair<iterator, iterator> equal_range(const key_type &k);

        allocator_type get_allocator() const { return avl.get_allocator(); }
    };

};
#endif
