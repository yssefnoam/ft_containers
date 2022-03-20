#include <iostream>
#include <vector>
#if NS == ft
  #include "vector.hpp"
#else
  #define NS  std
#endif

#define EL std::endl;

int main()
{


  if (typeid(std::iterator_traits<std::istream_iterator<int> >::iterator_category) == typeid(std::input_iterator_tag))
    std::cout << "random"<<std::endl;

  // std::istream_iterator<int> b(std::cin), last;

  // // int a[5] = {1, 2, 3, 4, 5};
  // NS::vector<int> v(b, a + 5);

  // // v.reserve(8);
  // std::cout << v.size() << std::endl;
  // std::cout << v.capacity() << std::endl;
  // std::cout << "-------------" << std::endl;

  // NS::vector<int>::iterator it;
  // it = v.begin();
  // for (; it != v.end(); it++)
  //   std::cout << *it << std::endl;
  // std::cout << "-------------" << std::endl;
  // // std::istream_iterator<int> b(std::cin), last;
  // int b[3]={-1,-2,-3};
  // v.insert(v.begin(), b, b + 3);
  // it = v.begin();
  // for (; it != v.end(); it++)
  //   std::cout << *it << std::endl;
  // std::cout << "-------------" << std::endl;
  // std::cout << v.size() << std::endl;
  // std::cout << v.capacity() << std::endl;

}