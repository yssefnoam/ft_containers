#include <iostream>
#include <vector>
#include "vector.hpp"

int main()
{
	// std::vector<int> v;

	// iterator that will be checked

	int a[5] = {1,2,3,4,5};
	// std::vector<int> vec(a, a+5);
	ft::iterator<int> it(a);
	ft::iterator<int> it2(a);
	std::cout << *it2 << std::endl;
	it2++;
	it++;
	std::cout << *it2 << std::endl;
	std::cout << *it << std::endl;

	std::cout << *( 2 + it2 ) << std::endl;
	it -= 2;


}