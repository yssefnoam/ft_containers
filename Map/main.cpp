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
            std::cout << "(" << root->content->first << "," << root->content->second << ")"
                      << " ";
        printTree(root->right, level + 1, lvl);
    }
}

int main()
{
    {
        std::map<int, std::string> m;
        std::cout << std::boolalpha;
        std::cout << m.empty() << std::endl;
    }
    // system("leaks a.out");
    return 0;
}