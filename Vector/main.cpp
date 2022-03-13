#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
// #define NS  ft

int main()
{
  {

  NS::vector<int> v(5);
  std::cout << v.capacity()<< EL
  std::cout << v.size() << EL
  std::cout << "------------" << EL

  NS::vector<int>::iterator it = v.begin();
  for(; it < v.end(); it++)
    std::cout << *it << EL
  std::cout << "------------" << EL
  v.pop_back();
  v.pop_back();
  v.pop_back();

  v.resize(4,6);
  std::cout << v.capacity()<< EL
  std::cout << v.size() << EL
  std::cout << "------------" << EL

  it = v.begin();
  for(; it < v.end(); it++)
    std::cout << *it << EL
  std::cout << "------------" << EL

  v.assign(10,100);
  std::cout << v.capacity()<< EL
  std::cout << v.size() << EL
  std::cout << "------------" << EL

  v.clear();
  it = v.begin();
  for(; it < v.end(); it++)
    std::cout << *it << EL
  NS::vector<int> v2;
  v2 = v;
  std::cout << v2.capacity()<< EL
  std::cout << v2.size() << EL

  
  }
}