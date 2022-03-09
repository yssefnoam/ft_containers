namespace ft
{
#ifndef _FT_VECTOR_H
#define _FT_VECTOR_H
#include <memory>

	#include "iterator.hpp"
	#include "reverse_iterator.hpp"

	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T 											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference 	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef size_t										size_type;
		typedef myIter<pointer>								iterator;
		typedef myIter<const_pointer>						const_iterator;
		typedef myReverseIter<iterator>						reverse_iterator;
		typedef myReverseIter<const_iterator>				const_reverse_iterator;


	private:
		allocator_type	_allocator;
		pointer			_buffer;
		size_type		_capacity;
		size_type		_size;

	public:
		/* Member functions */

		// constructor
		explicit vector(const allocator_type &alloc = allocator_type())
		: _allocator(alloc)
		, _buffer()
		, _capacity()
		, _size()
		{}

		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
		: _allocator(alloc)
		, _capacity(n)
		, _size(n)
		{
			_buffer = _allocator.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(_buffer + i, val);
		}

		// template <class InputIterator>
		// vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());
		// vector(const vector &x);

		// // destructor
		~vector()
		{
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_buffer + i);
			_allocator.deallocate(_buffer, _capacity);
		}

		// // operator=
		// vector &operator=(const vector &x);

		// /* Iterators */

		// // begin
		iterator begin() { return iterator(_buffer); }
		const_iterator begin() const { return const_iterator(_buffer); }

		// // end
		iterator end() { return iterator(_buffer + _size); }
		const_iterator end() const { return iterator(_buffer + _size); }

		// // rbegin
		reverse_iterator rbegin() {return reverse_iterator(--end());}
		const_reverse_iterator rbegin() const {return const_reverse_iterator(--end());}

		// // rend
		reverse_iterator rend() {return reverse_iterator(--begin());}
		const_reverse_iterator rend() const { return const_reverse_iterator(--begin()); }

		// /* Capacity */

		// // size
		size_type size() const { return _size; }

		// // max_size
		size_type max_size() const {return _allocator.max_size();}

		// // resize
		// void resize(size_type n, value_type val = value_type());

		// // capacity
		size_type capacity() const { return _capacity; }

		// // empty
		bool empty() const { return _size ? false : true; }

		// // reserve
		// void reserve(size_type n);

		// /* Element access */

		// // operator[]
		reference operator[](size_type n){ return *(begin() + n); }
		const_reference operator[](size_type n) const { return *(begin() + n); }

		// // at
		reference at(size_type n)
		{
			if (n > _size)
				throw std::out_of_range("vector");
			return *(begin() + n);
		}
		const_reference at(size_type n) const
		{
			if (n > _size)
				throw std::out_of_range("vector");
			return *(begin() + n);
		}

		// front
		reference front() { return *begin(); }
		const_reference front() const { return *begin(); }

		// back
		reference back() {return *(end()-1);}
		const_reference back() const;

		// /* Modifiers */

		// // assign
		// template <class InputIterator>
		// void assign(InputIterator first, InputIterator last);
		// void assign(size_type n, const value_type &val);

		// // push_back
		// void push_back(const value_type &val);

		// // pop_back
		// void pop_back();

		// // insert
		// iterator insert(iterator position, const value_type &val);
		// void insert(iterator position, size_type n, const value_type &val);
		// template <class InputIterator>
		// void insert(iterator position, InputIterator first, InputIterator last);

		// // erase
		// iterator erase(iterator position);
		// iterator erase(iterator first, iterator last);

		// // swap
		// void swap(vector &x);

		// // clear
		void clear()
		{
			for (size_type i=0; i < _size; i++)
				_allocator.destroy(_buffer[i]);
		}

		// /* Allocator */

		// get_allocator
		allocator_type get_allocator() const { return _allocator; }

		// /* Non-member function overloads */

		// relational operators
		// template <class T, class Alloc>
		// bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		// template <class T, class Alloc>
		// bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		// template <class T, class Alloc>
		// bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		// template <class T, class Alloc>
		// bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		// template <class T, class Alloc>
		// bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		// template <class T, class Alloc>
		// bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		// // swap
		// template <class T, class Alloc>
		// void swap(vector<T, Alloc> &x, vector<T, Alloc> &y);

	
	};
#endif
}
