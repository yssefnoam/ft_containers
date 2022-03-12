#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
#define NS std

int main()
{
  NS::vector<int> vec;
  vec.reserve(4);
  std::cout << vec.capacity() << EL
  std::cout << vec.size() << EL
  NS::vector<int>::iterator it;
  for(it = vec.begin(); it < vec.end(); it++)
    std::cout << *it << EL
  vec.resize(3);
  std::cout << "-----" << EL
  std::cout << vec.capacity() << EL
  std::cout << vec.size() << EL
  for(it = vec.begin(); it < vec.end(); it++)
    std::cout << *it << EL


}