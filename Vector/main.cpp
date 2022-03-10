#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
#define NS std
int main()
{
	NS::vector<int> vec(5,10);
	std::cout << "vec " <<vec.size() << EL
	std::cout << "vec " <<vec.capacity() << EL
	std::cout << "-----------"<< EL
	// vec.push_back(2);

	vec.reserve(6);
	std::cout << "-----------"<< EL
	NS::vector<int>::iterator it = vec.begin();
	for (; it < vec.end(); it++)
		std::cout << *it  << EL
	std::cout << "-----------"<< EL
	std::cout << "vec " <<vec.size() << EL
	std::cout << "vec " <<vec.capacity() << EL

}