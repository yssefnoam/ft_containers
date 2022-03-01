#include <iostream>
#include <vector>
#include "vector.hpp"

int main()
{
	// std::vector<int> v;

	// iterator that will be checked

	int a[5] = {1,2,3,4,5};
	std::vector<int> vec(a, a+5);
	std::vector<int>::iterator it = vec.begin();

}