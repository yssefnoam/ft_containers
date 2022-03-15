#ifndef _ENABLE_IF_HPP_
#define _ENABLE_IF_HPP_

template <bool Cond, class T = void>
struct enable_if {};

template <class T>
struct enable_if<true, T>
{ typedef T type; };

#endif