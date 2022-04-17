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
        ft::Tree<int, int> tree;
        tree.add(1,1);
        tree.add(2,1);
        tree.add(3,1);
        tree.add(1,1);
        // int a = 1;
        tree.remove(1);
        tree.change(2,2) = 2;
        std::cout << tree.size()<< std::endl;
        printTree(tree.root(),0,0);
        std::cout << std::endl;
        printTree(tree.root(),0,1);
        std::cout << std::endl;
    }
    system("leaks a.out");
    return 0;
}