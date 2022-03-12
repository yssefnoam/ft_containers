#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
#define NS ft

int main()
{
  NS::vector<int> vec;
  vec.reserve(3);
  std::cout << vec.capacity() << EL
  std::cout << vec.size() << EL
  NS::vector<int>::iterator it;
  for(it = vec.begin(); it < vec.end(); it++)
    std::cout << *it << EL
  vec.push_back(10);
  std::cout << "-----" << EL
  std::cout << vec.capacity() << EL
  std::cout << vec.size() << EL
  for(it = vec.begin(); it < vec.end(); it++)
    std::cout << *it << EL
}