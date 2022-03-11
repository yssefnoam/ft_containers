#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
#define NS std

int main()
{
  std::vector<int> vec;
  vec.reserve(5);
  std::cout << vec.capacity() << EL
  std::cout << vec.size() << EL
  vec.push_back(0);
  vec.push_back(0);
  vec.push_back(0);
  std::cout << "-----" << EL
  std::cout << vec.capacity() << EL
  std::cout << vec.size() << EL


}