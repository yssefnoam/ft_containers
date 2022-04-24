// make_pair example
#include <utility>	// std::pair
#include <iostream> // std::cout
#include "node.hpp"
#include "make_pair.hpp"
#include "map.hpp"
#include <map>
#include <vector>
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
    {
        ft::map<int, int> m;
        m[1] = 1;
        m[6] = 2;
        m[7] = 2;
        m[15] = 2;
        m[31] = 2;
        m[12] = 14;
        m[8] = 2;
        m[17] = 2;
        m[9] = 2;
        m[5] = 2;
        m[-9] = 2;
        m[-2] = 2;

        // m.erase(1);
        // m.erase(8);
        // m.erase(6);
        // m.erase(7);
        // m.erase(15);
        // m.erase(31);
        // m.erase(12);
        // m.erase(8);
        // m.erase(17);
        // m.erase(9);
        // m.erase(5);
        // m.erase(-9);
        // m.erase(-2);

        // std::cout << m.size() <<std::endl;
        // m.clear();
        // std::cout << m.size() <<std::endl;
        m.test();

    }
    // system("leaks a.out");
    return 0;
}