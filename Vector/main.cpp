#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
#define NS std

int main()
{
	NS::vector<int> vec(10,10);
	NS::vector<int>::iterator cit = vec.begin();
	std::cout << *cit << EL
	*cit = 2;
	std::cout << *cit << EL
	// cit[0] = 11;
	std::cout << *cit << EL
}