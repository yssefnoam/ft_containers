#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
// #define NS  std

int main()
{

int a[5] = {1,2,3,4,5};
NS::vector<int> v(a, a + 4);
std::cout << v.size()      << EL
std::cout << v.capacity()  << EL
std::cout << "------------" << EL
NS::vector<int>::iterator it;
it = v.begin();
for(;it!= v.end();it++)
  std::cout << *it << EL
std::cout << "------------" << EL

v.reserve(6);
v.insert(v.begin(), 0);
it = v.begin();
for(;it!= v.end();it++)
  std::cout << *it << EL
std::cout << "------------" << EL
std::cout << v.size()      << EL
std::cout << v.capacity()  << EL
}