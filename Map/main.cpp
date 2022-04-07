// make_pair example
#include <utility>	// std::pair
#include <iostream> // std::cout
#include "pair.hpp"
#include "make_pair.hpp"
#include "map.hpp"

int main()
{
	ft::Node<int, int> one(10,1);
	ft::Node<int, int> two(10,1);
    one.right = &two;
	std::cout << one.right->one << std::endl;
	return 0;
}