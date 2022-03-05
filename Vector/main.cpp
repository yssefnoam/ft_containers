#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
#define STD  ft

int main()
{
	STD::vector<int> vec(10,10);
	STD::vector<int>::const_iterator cit = vec.begin();
	std::cout << *cit << EL
}