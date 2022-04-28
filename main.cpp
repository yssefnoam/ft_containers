#include <iostream>
#include <sys/time.h>
#include <vector>
#include <map>
#include <stack>
#include <__tree>
#include <memory>


typedef std::__tree<int, std::less<int>, std::allocator<int> > base;

int main()
{
    base  tst((std::less<int>()));

	return 0;
}