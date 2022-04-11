// make_pair example
#include <utility>	// std::pair
#include <iostream> // std::cout
// #include "node.hpp"
// #include "make_pair.hpp"
// #include "map.hpp"
#include <map>
#include <vector>

template<class Node>
void printTree(Node *root)
{
    if(root!=NULL)
    {
        printTree(root->left);
        printTree(root->right);
        std::cout << root->content.first << std::endl;
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
    std::map<int, int> map;
    map[1] = 1;
    std::pair<*int, bool> val;
    val  = map.insert(std::make_pair(1,1));
    return 0;
}