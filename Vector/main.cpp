#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;

int main()
{
	// std::vector<int> v(3, 0);
	std::vector<int> v2(4, 0);
	// std::cout << &(*(v.begin())) << EL

	// std::cout << v.size() << EL
	// std::cout << v.capacity() << EL
	// std::cout << "v " << &(*(v.begin())) << EL

	// // v = std::vector<int>();
	// // v.push_back(10);

	// std::cout << v.size() << EL
	// std::cout << v.capacity() << EL
	// std::cout << "v " << &(*(v.begin())) << EL
	// std::cout << std::distance(v.begin(), v.end()) << EL
	std::vector<int>::iterator it = v2.begin();
	std::cout << it.base() << EL
	// std::cout << &(v2[0]) << EL
}