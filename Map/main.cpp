// make_pair example
#include <utility>	// std::pair
#include <iostream> // std::cout
#include "node.hpp"
#include "make_pair.hpp"
// #include "map.hpp"
#include <map>
#include <vector>


int main()
{
    Node<pair<int, int> > *root=NULL;
    root = new Node<pair<int, int> >(make_pair(10,10));
    return 0;
}