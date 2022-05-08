#include <iostream>
#include "map.hpp"

int main()
{
    ft::map<int, int> m;
    m.insert(ft::make_pair(1,1));
    std::cout << m.begin()->first << std::endl;
}