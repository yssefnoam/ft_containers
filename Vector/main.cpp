#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
#define NS ft
int main()
{
	NS::vector<int> vec(10,10);
	std::cout << vec.back() << EL
	std::cout << vec.front() << EL
	std::cout << vec.at(1) << EL
}