#ifndef ft_vector
#define ft_vector
#include <memory>

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	private:
	public:
		/* Member functions */

		// constructor
		explicit vector(const allocator_type &alloc = allocator_type());
		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type());
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());
		vector(const vector &x);

		// destructor
		~vector();

		// operator=
		vector &operator=(const vector &x);

		/* Iterators */

		// begin
		iterator begin();
		const_iterator begin() const;

		// end
		iterator end();
		const_iterator end() const;

		// rbegin
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;

		// rend
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		/* Capacity */

		// size
		size_type size() const;

		// max_size
		size_type max_size() const;

		// resize
		void resize (size_type n, value_type val = value_type());

		// capacity
		size_type capacity() const;

		// empty
		bool empty() const;

		// reserve
		void reserve (size_type n);

		/* Element access */

		// operator[]
		reference operator[] (size_type n);
		const_reference operator[](size_type n) const;

		// at
		reference at (size_type n);
		const_reference at(size_type n) const;

		// front
		reference front();
		const_reference front() const;

		// back
		reference back();
		const_reference back() const;

		/* Modifiers */

		// assign
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last);
		void assign (size_type n, const value_type& val);

		// push_back
		void push_back (const value_type& val);

		// pop_back
		void pop_back();

		// insert
		iterator insert (iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last);

		// erase
		iterator erase (iterator position);
		iterator erase(iterator first, iterator last);

		// swap
		void swap (vector& x);

		// clear
		void clear();


		/* Allocator */

		// get_allocator
		allocator_type get_allocator() const;

		/* Non-member function overloads */

		// relational operators
		template <class T, class Alloc>
		bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		template <class T, class Alloc>
		bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		template <class T, class Alloc>
		bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		template <class T, class Alloc>
		bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		template <class T, class Alloc>
		bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		template <class T, class Alloc>
		bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);
		// swap
		template <class T, class Alloc>
		void swap(vector<T, Alloc> &x, vector<T, Alloc> &y);

		/* Template specializations */

		// vector<bool>
		template <class T, class Alloc = allocator<T> >
		class vector; // generic template
		template <class Alloc>
		class vector<bool, Alloc>; // bool specialization
	};
}

#endif