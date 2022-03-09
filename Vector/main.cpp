#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
#define NS ft
int main()
{
	NS::vector<int> vec(5,10);
	std::cout << "vec " <<vec.size() << EL
	std::cout << "vec " <<vec.capacity() << EL
	std::cout << vec.at(0) << EL
	
}