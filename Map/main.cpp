// make_pair example
#include <utility>	// std::pair
#include <iostream> // std::cout
#include "node.hpp"
#include "make_pair.hpp"
// #include "map.hpp"
#include <map>
#include <vector>
#include "avl.hpp"
#include <functional>
#define SEPARATE std::cout << "-------------" << std::endl;

template<class Node>
void printTree(Node *root, int level, std::string str)
{
    if(root!=NULL)
    {
        printTree(root->left, level + 1, "left");
        std::cout << "level = " << level << " " << root->content->first << "; " << str << std::endl;
        printTree(root->right, level + 1, "right");
    }
}

int main()
{
    {
        Tree<int, int> tree;
        tree.insert(new pair<const int, int>(15, 1));
        tree.insert(new pair<const int, int>(11, 1));
        tree.insert(new pair<const int, int>(10, 1));

        printTree(tree.root(), 0, "root");
        SEPARATE
        tree.test();
        printTree(tree.root(), 0, "root");
        SEPARATE
    }
    // system("leaks a.out");
    return 0;
}