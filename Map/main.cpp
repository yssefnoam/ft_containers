// // make_pair example
// #include <utility>	// std::pair
// #include <iostream> // std::cout
// #include "node.hpp"
// #include "make_pair.hpp"
// #include "map.hpp"
// #include <map>
// #include <vector>
// #include "avl.hpp"
// #include <functional>
// #define SEPARATE std::cout << "-------------" << std::endl;


// template<class Node>
// void printTree(Node *root, int level, int lvl)
// {
//     if(root!=NULL)
//     {
//         printTree(root->left, level + 1, lvl);
//         if (lvl == level)
//             std::cout << "([" << root->content->first << "]," << root->content->second << ")"
//                       << " ";
//         printTree(root->right, level + 1, lvl);
//     }
// }

// int main()
// {
//     // int a, b;
//     // a = b = 0;
//     // while(a != 3)
//     //     std::cout << a << b << std::endl, a++, b++;
//     {
//         std::map<int, int> m;
//         m[0] = 9;
//         std::map<int, int>::iterator it = m.begin();
//         --it;
//     }
//     // system("leaks a.out");
//     return 0;
// }
#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << (*it).first << " => " << it->second << '\n';

  return 0;
}