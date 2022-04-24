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

    Node(Pair *cnt) : content(cnt), left(NULL), right(NULL), parent(NULL) {}
};

#endif