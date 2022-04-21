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
    {
        ft::map<int, int> m;
        m[1] = 0;
        m[6] = 0;
        m[7] = 0;
        m[8] = 0;
        m[9] = 0;
        m[2] = 0;
        m[3] = 0;
        m[4] = 0;
        m[5] = 0;
        ft::map<int, int>::iterator it = m.begin();
        ++it;
        std::cout << it->first << std::endl;
        ++it;
        ++it;
        --it;
        std::cout << it->first << std::endl;
        --it;
        std::cout << it->first << std::endl;
        --it;
        std::cout << it->first << std::endl;
        --it;
    }
    // system("leaks a.out");
    return 0;
}