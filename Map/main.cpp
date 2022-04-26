// make_pair example
#include <utility>  // std::pair
#include <iostream> // std::cout
#include "node.hpp"
#include "make_pair.hpp"
#include "map.hpp"
#include <map>
#include <vector>
#include <functional>
#define SEPARATE std::cout << "-------------" << std::endl;

template <class Node>
void printTree(Node *root, int level, int lvl)
{
    if (root != NULL)
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
        std::map<char, int> mymap;
        std::map<char, int>::iterator itlow, itup;

        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;

        itlow = mymap.lower_bound('f'); // itlow points to b
        itup = mymap.upper_bound('f');
        if (itup != itlow)
            std::cout << "here" << std::endl;
        // std::cout << itup->first << std::endl;
        // std::cout << itup->second << std::endl;
    }

    // system("leaks a.out");
    return 0;
}