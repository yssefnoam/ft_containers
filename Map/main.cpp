#include "map.hpp"
#include <iostream>
#include <stdlib.h>

int main()
{
    {

    ft::map<int, int> m;
    for (int i = 0; i != 5000; i++)
        m.insert(ft::make_pair(i, i));

    m.insert(ft::make_pair(0, 0));
    std::cout << "-------" << std::endl;
    ft::map<int, int>::iterator it;
    for(it = m.begin(); it != m.end();it++)
        std::cout << "here " << it->first << std::endl;
    std::cout << "size " << m.size() << std::endl;
    m.clear();
    for(it = m.begin(); it != m.end();it++)
        std::cout << "erase" << it->first << std::endl;
    }
    system("leaks a.out");

    
}