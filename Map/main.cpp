// make_pair example
#include <utility>	// std::pair
#include <iostream> // std::cout
#include "node.hpp"
#include "make_pair.hpp"
#include "map.hpp"
#include <map>
#include <vector>
#include "avl.hpp"
#include <functional>
#define SEPARATE std::cout << "-------------" << std::endl;


template<class Node>
void printTree(Node *root, int level, int lvl)
{
    if(root!=NULL)
    {
        printTree(root->left, level + 1, lvl);
        if (lvl == level)
            std::cout << "([" << root->content->first << "]," << root->content->second << ")"
                      << " ";
        printTree(root->right, level + 1, lvl);
    }
}

int main()
{
    // int a, b;
    // a = b = 0;
    // while(a != 3)
    //     std::cout << a << b << std::endl, a++, b++;
    {
        ft::map<int, int> m;
        m[1] = 1;
        m[2] = 2;
        m[3] = 3;
        m[4] = 4;
    }
    system("leaks a.out");
    return 0;
}