#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
#define NS ft
int main()
{
	NS::vector<int> vec(10,10);
	std::cout << "vec " <<vec.size() << EL
	std::cout << "vec " <<vec.capacity() << EL
	NS::vector<int> v = vec;
	std::cout << "v "<< v.size() << EL
	std::cout << "v "<< v.capacity() << EL
	vec = v;
	std::cout << "vec " <<vec.size() << EL
	std::cout << "vec " <<vec.capacity() << EL
	
}