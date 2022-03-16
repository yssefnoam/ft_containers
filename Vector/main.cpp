#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
// #define NS  ft

int main()
{

// std::istream_iterator<int> iterBegin( std::cin ), iterEnd;

// int a[5] = {1,2,3,4,5};
NS::vector<int> v(20,10);

NS::vector<int>::iterator it;
it = v.begin();
for(; it < v.end(); it++)
  std::cout << *it << EL

v.erase(v.begin(), v.begin() + 5);
std::cout << "------------" << EL

it = v.begin();
for(; it < v.end(); it++)
  std::cout << *it << EL
  
}