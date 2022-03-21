#include <iostream>
#include <vector>
#if NS == ft
  #include "vector.hpp"
#else
  #define NS  std
#endif
  // #define NS  std

int main()
{


  // if (typeid(std::iterator_traits<std::istream_iterator<int> >::iterator_category) == typeid(std::input_iterator_tag))
    // std::cout << "random"<<std::endl;

  // std::istream_iterator<int> b(std::cin), last;

  NS::vector<int> v(1,1);
  NS::vector<int>::iterator it;

  it = v.begin();
  for(; it != v.end();it++)
    std::cout << "v: " << *it << std::endl;
  std::cout << "------" << std::endl;

  NS::vector<int> v1(1,0);
  NS::swap(v,v1);
  it = v.begin();
  for(; it != v.end();it++)
    std::cout << "v: " << *it << std::endl;
}