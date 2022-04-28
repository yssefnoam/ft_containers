
#include "map.hpp"
#include <map>
#include <iostream>
int main ()
{

    {
        ft::map<char,int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;

		ft::map<char,int>::reverse_iterator rit= mymap.begin();
		// for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
        // {
            std::cout <<" => " << std::endl;
            std::cout << rit->first << " => " << rit->second << std::endl;
        // }
    }
}