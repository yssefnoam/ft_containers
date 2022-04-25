// make_pair example
#include <utility>	// std::pair
#include <iostream> // std::cout
#include "node.hpp"
#include "make_pair.hpp"
#include "map.hpp"
#include <map>
#include <vector>
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
    {
        ft::map<int,int> m;
        m[3] = 1;
        m[4] = 1;
        m[0] = 1;
        m[1] = 1;
        m[5] = 1;
        m[2] = 1;
        m.test();
        // ft::map<int, int>::iterator it = m.begin();
        // std::cout << it->first << std::endl;
        // it++;
        // std::cout << it->first << std::endl;
        // it++;
        // std::cout << it->first << std::endl;
        // it++;
        // std::cout << it->first << std::endl;

    }
    // system("leaks a.out");
    return 0;
}