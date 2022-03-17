#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
// #define NS  std

int main()
{

NS::vector<int> v(1,10);
// std::cout << v.size()      << EL
// std::cout << v.capacity()  << EL
std::cout << "------------" << std::endl;
std::cout << *(v.end() - 1) << EL

// for(;it!= v.begin();--it)
//   std::cout << *it << EL
// std::cout << "------------" << EL

// v.insert(v.begin(), 0);
// it = v.begin();
// for(;it!= v.end();it++)
//   std::cout << *it << EL
// std::cout << "------------" << EL
// std::cout << v.size()      << EL
// std::cout << v.capacity()  << EL
}