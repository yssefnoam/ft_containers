#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
#define NS ft

int main()
{
  NS::vector<int> vec;
  vec.reserve(4);
  std::cout << vec.capacity() << EL
  std::cout << vec.size() << EL
  vec.resize(4);
  std::cout << "-----" << EL
  std::cout << vec.capacity() << EL
  std::cout << vec.size() << EL


}