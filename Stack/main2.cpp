#include <iostream>
#include "stack.hpp"

int main()
{
    ft::stack<int> s;
    s.push(1);
    std::cout << s.top() << std::endl;
}