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
    {
        std::map<int, int> m;
        m[1] = 0;
        m[-1] = 0;
        m[5] = 0;
        std::map<int, int>::iterator it = m.end();
        --it;
        std::cout << it->first << std::endl;
        --it;
        std::cout << it->first << std::endl;
        --it;
        std::cout << it->first << std::endl;
        ++it;
        std::cout << it->first << std::endl;
        ++it;
        std::cout << it->first << std::endl;
        ++it;
        // std::cout << "size = "<<m.size() << std::endl;
        // it++;
        // m.erase(5);
        // std::cout << "size = "<<m.size() << std::endl;
        // it--;
        // std::cout << it->first << std::endl;
    }
    // system("leaks a.out");
    return 0;
}