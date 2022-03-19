#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
// #define NS  std

int main()
{

NS::vector<int> v(4,4);
v.reserve(8);

NS::vector<int>::iterator it;
it = v.begin();
for (; it != v.end(); it++)
  std::cout << *it << std::endl;
std::cout << "-------------"  << std::endl;
std::cout << v.size()      << std::endl;
std::cout << v.capacity()  << std::endl;
std::cout << "-------------"  << std::endl;
v.insert(v.begin(), 1, 1);
it = v.begin();
for (; it != v.end(); it++)
  std::cout << *it << std::endl;
std::cout << "-------------"  << std::endl;
std::cout << v.size()      << std::endl;
std::cout << v.capacity()  << std::endl;

}