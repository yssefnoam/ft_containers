// make_pair example
#include <utility>	// std::pair
#include <iostream> // std::cout
// #include "node.hpp"
// #include "make_pair.hpp"
// #include "map.hpp"
#include <map>
#include <vector>
// #include "avl.hpp"
#include <functional>

template<class Node>
void printTree(Node *root, int level)
{
    if(root!=NULL)
    {
        printTree(root->left, level + 1);
        std::cout << "level " << level << " " << root->content->first << std::endl;
        printTree(root->right, level + 1);
    }
}

int* tst()
{
    int a = 10;
    return &a;
}
int main()
{
    // {
    //     Tree<int, int> tree;
    //     tree.addNode(tree.newNode(new pair<const int, int>(10, 1)));
    //     // tree.addNode(tree.newNode(new pair<const int, int>(11, 2)));
    //     tree.addNode(tree.newNode(new pair<const int, int>(9, 3)));
    //     tree.addNode(tree.newNode(new pair<const int, int>(8, 4)));
    //     // tree.addNode(tree.newNode(new pair<const int, int>(7, 4)));
    //     // tree.addNode(tree.newNode(new pair<const int, int>(5, 4)));
    //     // tree.addNode(tree.newNode(new pair<const int, int>(6, 4)));
    //     // std::cout << tree.size() << std::endl;
    //     std::cout << tree.height(tree.root()->left) << std::endl;
    //     std::cout << tree.height(tree.root()->right) << std::endl;
    // }
    *(tst()) =  20;
    // system("leaks a.out");
    return 0;
}