namespace ft
{
#ifndef _FT_VECTOR_H
#define _FT_VECTOR_H
#include <memory>

	#include "iterator.hpp"
	#include "reverse_iterator.hpp"
	#include "enable_if.hpp"
	#include "is_integral.hpp"

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
		typedef reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef reverse_iterator<iterator>					reverse_iterator;


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
			_buffer = _allocator.allocate(size());
			for (size_type i = 0; i < size(); i++)
				_allocator.construct(_buffer + i, val);
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last
		, const allocator_type &alloc = allocator_type()
		, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false)
		: _allocator(alloc)
		, _capacity()
		, _size()
		{
			if (typeid(typename ft::iterator_traits<InputIterator>::iterator_category) == typeid(std::random_access_iterator_tag)
			 || typeid(typename ft::iterator_traits<InputIterator>::iterator_category) == typeid(std::bidirectional_iterator_tag))
			{
				size_type size = 0;
				InputIterator tmp = first;
				for (; tmp != last; tmp++)
					size++;
				_buffer = _allocator.allocate(size);
				for(; first != last; first++)
					push_back(*first);
			}
			else
				for(; first != last; first++)
					push_back(*first);
		}

		vector(const vector &x)
		: _allocator(x.get_allocator())
		, _capacity(x.size())
		, _size(x.size())
		{
			_buffer = _allocator.allocate(size());
			for (size_type i = 0; i < size(); i++)
				_buffer[i] = x[i];
		}

		// operator=
		vector &operator=(const vector &x)
		{
			for (size_type i = 0; i < size(); i++)
				_allocator.destroy(_buffer + i);
			if (x.size() <= size())
				_size = x.size();
			else
			{
				_allocator.deallocate(_buffer, _capacity);
				_size = x.size();
				_capacity = x.size();
				_buffer = _allocator.allocate(size());
			}
			for (size_type i = 0; i < size(); i++)
				_buffer[i] = x[i];
			return *this;
		}

		/* destructor*/
		~vector()
		{
			clear();
			_allocator.deallocate(_buffer, _capacity);
		}

		// /* Iterators */

		// begin
		iterator begin() { return iterator(_buffer); }
		const_iterator begin() const { return const_iterator(_buffer); }

		// end
		iterator end() { return iterator(_buffer + size()); }
		const_iterator end() const { return iterator(_buffer + size()); }

		// rbegin
		reverse_iterator rbegin() {return reverse_iterator(end());}
		const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}

		// rend
		reverse_iterator rend() {return reverse_iterator(begin());}
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

		/* Capacity */

		// size
		size_type size() const { return _size; }

		// max_size
		size_type max_size() const {return _allocator.max_size();}

		// resize
		void resize(size_type n, value_type val = value_type())
		{
			if (n > _capacity)
			{
				(n < _capacity * 2) ? reserve(_capacity * 2) : reserve(n);
				for (; _size < n; _size++)
					_allocator.construct(_buffer + _size, val);
			}
			else
			{
				if (n < size())
					while (n < size())
						pop_back();
				else
					for (; _size < n; _size++)
						_allocator.construct(_buffer + _size, val);
			}
		}

		// capacity
		size_type capacity() const { return _capacity; }

		// empty
		bool empty() const { return size() ? false : true; }

		// reserve
		void reserve(size_type n)
		{
			if (n > _capacity)
			{
				pointer tmp = _allocator.allocate(n);;
				for (size_type i = 0; i < size(); i++)
					tmp[i] = _buffer[i];
				for (size_type i = 0; i < size(); i++)
					_allocator.destroy(_buffer + i);
				_allocator.deallocate(_buffer, _capacity);
				_capacity	= n;
				_buffer		= tmp;
			}
		}

		/* Element access */

		// operator[]
		reference operator[](size_type n) { return *(begin() + n); }
		const_reference operator[](size_type n) const { return *(begin() + n); }

		// at
		reference at(size_type n)
		{
			if (n >= size())
				throw std::out_of_range("ft::vector");
			return *(begin() + n);
		}
		const_reference at(size_type n) const
		{
			if (n >= size())
				throw std::out_of_range("ft::vector");
			return *(begin() + n);
		}

		// front
		reference front() { return *begin(); }
		const_reference front() const { return *begin(); }

		// back
		reference back() {return *(end()-1);}
		const_reference back() const { return *(end() - 1); }

		// /* Modifiers */

		// assign
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false)
		{
			clear();
			size_type n = 0;
			InputIterator tmp = first;
			for (; tmp != last; tmp++)
				n++;
			if (n > size())
				reserve(n);
			while (first != last)
				push_back(*first++);
		}

		void assign(size_type n, const value_type &val)
		{
			clear();
			if (n > size())
				reserve(n);
			while (size() < n)
				push_back(val);
		}

		// push_back
		void push_back(const value_type &val) { resize(size() + 1, val); }

		// pop_back
		void pop_back() { _allocator.destroy(_buffer + (--_size)); }

		// insert
		iterator insert(iterator position, const value_type &val)
		{
			if (size() + 1 <= capacity())
				push_back(val);
			else
			{
				int index = 0;
				for (iterator it = begin(); it != position; it++)
					index++;
				push_back(val);
				position = begin();
				while(index--)
					position++;
			}
			iterator it = end() - 1;
			for (; it != position; it--)
			{
				_allocator.destroy(&(*it));
				*it = *(it - 1);
			}
			_allocator.destroy(&(*it));
			*it = val;
			return position;
		}
		void insert(iterator position, size_type n, const value_type &val)
		{
			if (n > 0)
				if (size() + n <= capacity())
				{
					while(n--)
					{
					}
				}
				else
				{
				}
		}

		// template <class InputIterator>
		// void insert(iterator position, InputIterator first, InputIterator last);

		// erase
		iterator erase(iterator position)
		{
			iterator copy = position;
			for (; position != end() - 1; position++)
			{
				_allocator.destroy(&(*position));
				*position  = *(position + 1);
			}
			_size--;
			return copy;
		}
		iterator erase(iterator first, iterator last)
		{
			iterator tmp = first;
			size_type n = 0;
			for (; tmp != last; tmp++)
				n++;
			tmp = first;
			for (; tmp != last; tmp++)
				_allocator.destroy(&(*tmp));
			tmp = first;
			for (; last != end(); last++)
			{
				*first = *last;
				_allocator.destroy(&(*last));
				first++;
			}
			_size -= n;
			return tmp;
		}

		// swap
		// void swap(vector &x);

		// clear
		void clear() { while (size()) pop_back(); }

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

		// swap
		// template <class T, class Alloc>
		// void swap(vector<T, Alloc> &x, vector<T, Alloc> &y);

	
	};
#endif
}
