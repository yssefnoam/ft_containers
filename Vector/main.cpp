#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
// #define NS  ft

int main()
{
  NS::vector<int> vec(5,5);
  std::cout << vec.capacity() << EL
  std::cout << vec.size() << EL
  std::cout << "-----" << EL
  vec.push_back(1);
  std::cout << vec.capacity() << EL
  std::cout << vec.size() << EL
  std::cout << "-----" << EL
  vec.push_back(1);
  vec.resize(4);
  vec.push_back(1);
  vec.resize(5);
  vec.pop_back();
  vec.pop_back();
  vec.pop_back();
  vec.pop_back();
  vec.resize(6);
  vec.push_back(1);
  vec.push_back(1);
  vec.push_back(1);
  vec.push_back(1);
  std::cout << vec.capacity() << EL
  std::cout << vec.size() << EL
  std::cout << "-----" << EL
  NS::vector<int>::iterator it;
  for(it = vec.begin(); it < vec.end(); it++)
    std::cout << *it << EL
  // vec.push_back(10);
  // std::cout << "-----" << EL
  // std::cout << vec.capacity() << EL
  // std::cout << vec.size() << EL
  // for(it = vec.begin(); it < vec.end(); it++)
  //   std::cout << *it << EL
  // std::cout << "-----" << EL
}