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
        std::map<int, int> m;
        m[1] = 1;
        m[8] = 2;
        m[6] = 2;
        m[7] = 2;
        m[15] = 2;
        m[31] = 2;
        m[12] = 2;
        m[8] = 2;
        m[17] = 2;
        m[9] = 2;
        m[5] = 2;
        m[-9] = 2;
        m[-2] = 2;
        const std::map<int, int> m2 =m ;
        std::map<int, int>::iterator it =m2.begin() ;
        it++;

    }
    // system("leaks a.out");
    return 0;
}