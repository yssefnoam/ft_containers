#include <iostream>
#include <vector>
#include "vector.hpp"

int main()
{
	// std::vector<int> v;

	// iterator that will be checked

	int a[5] = {1,2,3,4,5};
	ft::iterator<int> it(a);
	ft::iterator<int> it2(a);
	it++;
	if (it != it2)
		std::cout << "equal" << std::endl;

}