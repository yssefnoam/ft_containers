#ifndef _TREE_HPP
#define _TREE_HPP

#include "node.hpp"

template <class T>
struct Tree
{
private:
    Node *_root;

public:
    Tree() : _root(NULL) {}
    ~Tree() {}
};

#endif