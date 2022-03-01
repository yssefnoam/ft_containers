#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_

template <class T>
class iterator
{
public:
    typedef T value_type;
    typedef size_t difference_type;
    typedef T *pointer;
    typedef T &reference;
    typedef std::random_access_iterator_tag iterator_category;

private:
    pointer _base;

public:
    // default
    iterator(pointer base)
    {
        this->_base = base;
    }

    // copy
    iterator(const iterator &copy)
    {
        this->_base = copy._base;
    }

    // assign
    iterator& operator=(const iterator& copy)
    {
        this->_base = copy._base;
    }
    // ++it
    iterator operator++()
    {
        this->_base++;
        return *this;
    }
    // it++
    iterator operator++(int)
    {
        iterator tmp = *this;
        this->_base++;
        return tmp;
    }
    bool operator==(const iterator& other)
    {
        return (this->_base == other._base)? true : false;
    }

    bool operator!=(const iterator& other)
    {
        return !operator==(other);
    }
    reference operator*()
    {
        return *(this->_base);
    }
};

#endif