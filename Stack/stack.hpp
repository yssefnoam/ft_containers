namespace ft
{
#ifndef _FT_STACK_H
#define _FT_STACK_H

    #include "../Vector/vector.hpp"

    template <class T, class Container = ft::vector<T> >
    class stack
	{
        // constructor
        explicit stack (const container_type& ctnr = container_type());

        bool empty() const;

        size_type size() const;

        value_type& top();
        const value_type& top() const;

        void push(const value_type &val);

        void pop();
    };
    template <class T, class Container>
    bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
    template <class T, class Container>
    bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
    template <class T, class Container>
    bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
    template <class T, class Container>
    bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
    template <class T, class Container>
    bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
    template <class T, class Container>
    bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
#endif
}