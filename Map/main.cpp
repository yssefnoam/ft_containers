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
        tree.addNode(tree.newNode(new pair<const int, int>(10, 1)));
        tree.addNode(tree.newNode(new pair<const int, int>(8, 3)));
        tree.addNode(tree.newNode(new pair<const int, int>(9, 3)));
        tree.addNode(tree.newNode(new pair<const int, int>(12, 4)));
        tree.addNode(tree.newNode(new pair<const int, int>(11, 3)));
        printTree(tree.root(), 0, "root");
        tree.rotateRight((tree.root())->right);
        SEPARATE
        printTree(tree.root(), 0, "root");
    }
    // system("leaks a.out");
    return 0;
}