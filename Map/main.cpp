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
        ft::Tree<int, int> tree;
        tree.insert(new pair<const int, int>(5, 1));
        tree.insert(new pair<const int, int>(6, 1));
        tree.insert(new pair<const int, int>(3, 1));
        tree.insert(new pair<const int, int>(4, 1));
        tree.insert(new pair<const int, int>(1, 1));
        tree.insert(new pair<const int, int>(2, 1));
        tree.insert(new pair<const int, int>(0, 1));
        tree.insert(new pair<const int, int>(-1, 1));
        tree.insert(new pair<const int, int>(-2, 1));
        tree.insert(new pair<const int, int>(7, 1));
        tree.insert(new pair<const int, int>(8, 1));


        int a = 0;
        while(a<5)
        {
            printTree(tree.root(), 0, a++);
            std::cout << std::endl;
        }
        tree.test();
        
        // SEPARATE
        // tree.test();
        // printTree(tree.root(), 0, "root");
        // SEPARATE
    }
    // system("leaks a.out");
    return 0;
}