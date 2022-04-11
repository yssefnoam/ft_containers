#ifndef _TREE_HPP
#define _TREE_HPP

#include "node.hpp"
#include "pair.hpp"

template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
struct Tree
{
private:
    typedef Key key_type;
    typedef T mapped_type;
    typedef pair<const key_type, mapped_type> value_type;
    typedef Compare key_compare;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;

private:
    Node<value_type> *_root;

public:
    Tree() : _root(NULL) {}
    ~Tree() {}

    Node<value_type> *newNode(value_type p) { return new Node<value_type>(p); }

    bool empty() { return _root ? false : true; }

    Node<value_type> *left(Node<value_type> *node) { return node->left; }

    Node<value_type> *right(Node<value_type> *node) { return node->right; }
};

#endif