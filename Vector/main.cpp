#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
#define NS std
int main()
{
	NS::vector<int>::iterator it;
	NS::vector<int> vec(5,10);

	std::cout << "size: " << vec.size() << EL
	std::cout << "capa: " << vec.capacity() << EL
	for (it = vec.begin(); it < vec.end(); it++)
		std::cout << *it  << EL
	

	std::cout << "-----------" << EL
	vec.clear();
	vec.resize(12, 11);

	std::cout << "size: " << vec.size() << EL
	std::cout << "capa: " << vec.capacity() << EL

	for (it = vec.begin(); it < vec.end(); it++)
		std::cout << *it  << EL
}