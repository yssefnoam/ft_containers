#include "map.hpp"
#include <iostream>
#include <stdlib.h>

int main()
{
    {

        ft::map<int, int> m;
        for (int i = 0; i != 50000; i++)
            m.insert(ft::make_pair(i, i));
    }
}