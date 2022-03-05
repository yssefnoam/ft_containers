#ifndef _REVERSE_reverse_iterator_HPP_
#define _REVERSE_reverse_iterator_HPP_

template <class T>
class reverse_iterator
{
public:
    typedef T value_type;
    typedef size_t difference_type;
    typedef T *pointer;
    typedef T &reference;
    typedef std::random_access_reverse_iterator_tag iterator_category;

private:
    T _base;

public:
    // default
    reverse_iterator(ft::iterator<T> &it) : _base(it) {}

    reverse_iterator() : _base() {}

    // copy
    reverse_iterator(const iterator &copy)
    {
        this->_base = copy._base;
    }

    // assign
    reverse_iterator &operator=(const iterator &copy)
    {
        this->_base = copy._base;
    }
    // --it
    reverse_iterator operator--()
    {
        this->_base--;
        return *this;
    }
    // it--
    reverse_iterator operator--(int)
    {
        reverse_iterator tmp = *this;
        this->_base--;
        return tmp;
    }
    // ++it
    reverse_iterator operator++()
    {
        this->_base++;
        return *this;
    }
    // it++
    reverse_iterator operator++(int)
    {
        reverse_iterator tmp = *this;
        this->_base++;
        return tmp;
    }
    bool operator==(const reverse_iterator &other) { return (this->_base == other._base); }

    bool operator!=(const reverse_iterator &other) { return !operator==(other); }

    reference operator*() { return *(this->_base); }

    pointer operator->() { return operator*(); }

    reverse_iterator operator+(int &a) { return this->_base + a; }

    reverse_iterator operator-(int &a) { return iterator(this->_base - a); }

    void operator-=(int a) { this->_base -= a; }

    void operator+=(int a) { this->_base += a;}

    difference_type operator-(reverse_iterator &other) { return this->_base - other._base; }

    bool operator<(const reverse_iterator &other) { return this->_base < other._base; }

    bool operator>(const reverse_iterator &other) { return this->_base > other._base; }

    bool operator<=(const reverse_iterator &other) { return this->_base <= other._base; }

    bool operator>=(const reverse_iterator &other) { return this->_base >= other._base; }

    reference operator[](int index) { return *(this->_base + index);}
    pointer base(){return this->_base;}
};

template<class T>
reverse_iterator<T> operator+(int a,reverse_iterator<T> &it)
{
    reverse_iterator<T> tmp = it;
    return tmp + a;
}

#endif