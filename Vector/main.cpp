#include <iostream>
#include <vector>
#include "vector.hpp"
#include <vector>

int main(void)
{

	int a[5] = {1,2,3,4,5};
	ft::iterator<int> it(a);
	// std::vector<int> vec(a, a+5);
	// std::vector<int>::iterator it = vec.begin();
	// it++;
	// std::cout << *it << std::endl;
	// std::vector<int>::iterator it2(it);
	// std::cout << *it2 << std::endl;

	// --it;
	// if (it == it2)
	// 	std::cout << "equal" << std::endl;
	
	// std::cout << it.base() << std::endl;
	// std::cout << it2.base() << std::endl;

}