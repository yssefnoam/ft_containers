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
    // destructor
    // operator=


    /* Iterators */

    // begin
    // end
    // rbegin
    // rend


    /* Capacity */

    // size
    // max_size
    // resize
    // capacity
    // empty
    // reserve


    /* Element access */

    // operator[]
    // at
    // front
    // back


    /* Modifiers */

    // assign
    // push_back
    // pop_back
    // insert
    // erase
    // swap
    // clear


    /* Allocator */

    // get_allocator


    /* Non-member function overloads */

    // relational operators
    // swap


    /* Template specializations */

    // vector<bool>


    };
}

#endif