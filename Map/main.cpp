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

        mymap['x'] = 1001;
        mymap['y'] = 2002;
        mymap['z'] = 3003;

        std::cout << "mymap contains:\n";

        std::map<char, int>::iterator it = mymap.end();
        it--;

        if (mymap.value_comp()(*mymap.begin(), *it))
            std::cout << "true" << std::endl;
    }

    // system("leaks a.out");
    return 0;
}