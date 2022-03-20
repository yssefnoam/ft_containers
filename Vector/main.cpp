#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
// #define NS  std

int main()
{

int a[5] ={1,2,3,4,5};
NS::vector<int> v(a,a+5);
// v.reserve(8);
std::cout << v.size()      << std::endl;
std::cout << v.capacity()  << std::endl;
std::cout << "-------------"  << std::endl;

NS::vector<int>::iterator it;
it = v.begin();
for (; it != v.end(); it++)
  std::cout << *it << std::endl;
std::cout << "-------------"  << std::endl;
v.insert(v.end() + 1, 2, 0);
it = v.begin();
for (; it != v.end(); it++)
  std::cout << *it << std::endl;
std::cout << "-------------"  << std::endl;
std::cout << v.size()      << std::endl;
std::cout << v.capacity()  << std::endl;

}