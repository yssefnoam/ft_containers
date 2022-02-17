#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "vector.hpp"

using namespace std;
int main()
{
    {
        std::vector<int> vec(5);
        std::cout << vec.size() << std::endl; 
        std::cout << vec.capacity() << std::endl; 
        vec.push_back(10);
        std::cout << vec.size() << std::endl; 
        std::cout << vec.capacity() << std::endl; 
        std::cout << vec[7] << std::endl;
        std::cout << vec[9] << std::endl;
    }
    return 0;
}