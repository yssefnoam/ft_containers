#ifndef _IS_INTEGRAL_HPP_
#define _IS_INTEGRAL_HPP_

#include <cstddef>

template <class T>
struct is_integral
{
    typedef T type;
    bool value_type = false;
};
template <>
struct is_integral<bool>
{
    typedef bool type;
    bool value_type = true;
};

template <>
struct is_integral<char>
{
    typedef char type;
    bool value_type = true;
};
template <>
struct is_integral<char16_t>
{
    typedef char16_t type;
    bool value_type = true;
};
template <>
struct is_integral<char32_t>
{
    typedef char32_t type;
    bool value_type = true;
};
template <>
struct is_integral<wchar_t>
{
    typedef wchar_t type;
    bool value_type = true;
};
template <>
struct is_integral<signed char>
{
    typedef signed char type;
    bool value_type = true;
};
template <>
struct is_integral<short int>
{
    typedef short int type;
    bool value_type = true;
};
template <>
struct is_integral<int>
{
    typedef int type;
    bool value_type = true;
};
template <>
struct is_integral<long int>
{
    typedef long int type;
    bool value_type = true;
};
template <>
struct is_integral<long long int>
{
    typedef long long int type;
    bool value_type = true;
};
template <>
struct is_integral<unsigned char>
{
    typedef unsigned char type;
    bool value_type = true;
};
template <>
struct is_integral<unsigned short int>
{
    typedef unsigned short int type;
    bool value_type = true;
};
template <>
struct is_integral<unsigned int>
{
    typedef unsigned int type;
    bool value_type = true;
};
template <>
struct is_integral<unsigned long int>
{
    typedef unsigned long int type;
    bool value_type = true;
};
template <>
struct is_integral<unsigned long long int>
{
    typedef unsigned long long int type;
    bool value_type = true;
};

#endif