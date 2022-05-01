#ifndef _NODE_HPP
#define _NODE_HPP

#include "pair.hpp"

template <class Pair>
struct Node
{
    Pair *content;
    Node *left;
    Node *right;
    Node *parent;
    int height;

    Node(Pair *cnt, Node *parent)
    : content(cnt)
    , left(NULL)
    , right(NULL)
    , parent(parent)
    , height()
    {}
};

#endif