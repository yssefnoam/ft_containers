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
        ft::map<char, int> mymap;
        mymap.insert(ft::pair<char, int>('a', 100));
        mymap.insert(ft::pair<char, int>('z', 200));
        ft::pair<ft::map<char, int>::iterator, bool> ret;
        ret = mymap.insert(ft::pair<char, int>('a', 500));

        ft::map<char,int>::iterator it = mymap.begin();
        // for(;it != mymap.end(); it++)
            // std::cout << it->first << " " << it->second << std::endl;
        if(mymap.insert(it, ft::pair<char, int>('a', 300)) == it) // max efficiency inserting
            std::cout << it->first << " " << it->second << std::endl;
        // mymap.insert(it, std::pair<char, int>('c', 400));  

    }

    // system("leaks a.out");
    return 0;
}