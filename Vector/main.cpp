#include <iostream>
#include <memory>
#include <string>
#include <vector>
// #include "vector.hpp"

using namespace std;
int main()
{
    std::allocator<char>  myAllocator;

    std::vector<int> vec(myAllocator);
    return 0;
}