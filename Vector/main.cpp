#include <iostream>
#include <vector>
#include "vector.hpp"
#define EL std::endl;
#define NS ft
int main()
{
	NS::vector<int> vec(10);

	NS::vector<int>::reverse_iterator it = vec.rbegin();
	// NS::vector<int>::reverse_iterator it2 = vec.rend();
	std::cout << *it  << EL
}