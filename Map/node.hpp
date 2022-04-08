#ifndef _NODE_HPP
#define _NODE_HPP

#include "pair.hpp"

template <class Pair>
struct Node
{
    Pair content;
    Node *left;
    Node *right;

    // TODO: fix constructor 
    Node(Pair &cnt) : content(cnt), left(NULL), right(NULL) {}
};

#endif