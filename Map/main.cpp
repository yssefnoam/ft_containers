// make_pair example
#include <utility>	// std::pair
#include <iostream> // std::cout
// #include "node.hpp"
#include "make_pair.hpp"
// #include "map.hpp"
#include <map>
#include <vector>
#include "avl.hpp"
#include <functional>

template<class Node>
void printTree(Node *root, std::string str)
{
    if(root!=NULL)
    {
        printTree(root->left, "left");
        printTree(root->right, "right");
        std::cout << str << " "<<root->content->first << std::endl;
    }
}

int main()
{
    // {
    //     Node<pair<std::string, int> > *root = NULL;
    //     root = new Node<pair<std::string, int> >(make_pair("one", 1));

    //     root->left = new Node<pair<std::string, int> >(make_pair("two", 2));
    //     root->left->left = new Node<pair<std::string, int> >(make_pair("three", 4));
    //     root->left->right = new Node<pair<std::string, int> >(make_pair("four", 5));

    //     root->right = new Node<pair<std::string, int> >(make_pair("five", 3));
    //     root->right->left = new Node<pair<std::string, int> >(make_pair("six", 6));
    //     root->right->right = new Node<pair<std::string, int> >(make_pair("seven", 7));
    //     printTree(root->left);
    //     std::cout << "--------------" << std::endl;
    //     std::cout << root->content.first << std::endl;
    //     std::cout << "--------------" << std::endl;
    //     printTree(root->right);
    // }
    // system("leaks a.out");
    // std::map<int, int> map;
    // map[1] = 1;
    // std::pair<*int, bool> val;
    // val  = map.insert(std::make_pair(1,1));
    Tree<int,int> tree;
    Tree<int,int>::_Node *node = tree.newNode(new pair<const int,int>(10,1));
    tree.insertNode(node);
    node = tree.newNode(new pair<const int,int>(11,1));
    tree.insertNode(node);
    node = tree.newNode(new pair<const int,int>(12,1));
    tree.insertNode(node);
    // std::cout << "-----------" << std::endl;
    printTree(tree.root(), "root");
    // if(tree.root()->right)
        // std::cout << "left" << std::endl;
    // if (tree.search(11))
        // std::cout << tree.search(11)->content->first << std::endl;
    // // TODO: segfault
    // std::cout << "--------------" << std::endl;
    // node = tree.search(9);
    // if (node)
    //     std::cout << "true" << std::endl;
    // else
    //     std::cout << "false" << std::endl;
    return 0;
}