#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
// #define NS  ft

int main()
{

// std::istream_iterator<int> iterBegin( std::cin ), iterEnd;

int a[5] = {1,2,3,4,5};
// std::vector<int> v( iterBegin, iterEnd );
NS::vector<int> v( a, a+3 );
// std::cout << "------------" << EL
// std::cout << v.capacity() << std::endl;
// std::cout << v.size()     << std::endl;
// std::cout << "------------" << EL

// std::vector<int>::iterator it= v.begin();
// for(; it < v.end(); it++)
//   std::cout << *it << EL

  // NS::vector<int> v;
  // std::cout << v.end() - v.begin() << EL
  std::cout << v.capacity()<< EL
  std::cout << v.size() << EL
  // std::cout << "------------" << EL

  // std::cout <<   v.begin() - v.end(); 
  // NS::vector<int>::iterator it = v.begin();
  // for(; it < v.end(); it++)
  //   std::cout << *it << EL
  // std::cout << "------------" << EL
  // v.push_back(10);
  // v.pop_back();
  // v.pop_back();

  // v.resize(4,6);
  // std::cout << v.capacity()<< EL
  // std::cout << v.size() << EL
  // std::cout << "------------" << EL

  // it = v.begin();
  // for(; it < v.end(); it++)
  //   std::cout << *it << EL
  // std::cout << "------------" << EL

  // v.assign(10,100);
  // std::cout << v.capacity()<< EL
  // std::cout << v.size() << EL
  // std::cout << "------------" << EL

  // v.clear();
  // it = v.begin();
  // for(; it < v.end(); it++)
  //   std::cout << *it << EL
  // NS::vector<int> v2;
  // v2 = v;
  // std::cout << v2.capacity()<< EL
  // std::cout << v2.size() << EL

  
}