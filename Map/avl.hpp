#ifndef _TREE_HPP
#define _TREE_HPP

#include "node.hpp"
#include "pair.hpp"

template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
struct Tree
{
public:
    typedef const Key key_type;
    typedef T mapped_type;
    typedef pair<const key_type, mapped_type> value_type;
    typedef Compare key_compare;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef size_t size_type;

    typedef Node<value_type> _Node;

private:
    _Node *_root;
    size_type _size;
    key_compare _ft_compare;

public:
    Tree() : _root(NULL), _size(0) {}
    ~Tree() {}

    _Node *newNode(value_type *p) { return new _Node(p); }

    bool empty() { return _root ? false : true; }

    _Node *left(_Node *node) { return node->left; }

    _Node *right(_Node *node) { return node->right; }

    key_type &key(_Node *node) { return node->content->first; }

    size_type size() { return _size; }

    _Node *root() { return _root; }

    size_type height(_Node *node)
    {
        if (!node)
            return 0;
        size_type r = height(right(node));
        size_type l = height(left(node));

        return (r >= l ? r : l) + 1;
    }

    _Node *search(key_type k)
    {
        _Node *tmp = _root;
        while (tmp)
        {
            if (key(tmp) == k)
                return tmp;
            if (!_ft_compare(key(tmp), k))
                tmp = left(tmp);
            else
                tmp = right(tmp);
        }
        return NULL;
    }

    _Node *parent(_Node *node)
    {
        if (node == _root)
            return NULL;
        _Node *tmp = _root;
        while (right(tmp) != node && left(tmp) != node)
        {
            if (!_ft_compare(key(tmp), key(node)))
                tmp = left(tmp);
            else
                tmp = right(tmp);
        }
        return tmp;
    }

    void rotateLeft(_Node *node)
    {
        _Node *node_parent = parent(node);
        _Node *child = NULL;
        // normal Node
        if (node_parent)
        {
            if (right(node_parent) == node)
            {
                (right(node_parent)) = right(node);
                (right(node)) = NULL;
                (left(right(node_parent))) = node;
            }
        }
        // root Node
        if (node_parent)
        {
            if (right(node_parent) == node)
            {
                (right(node_parent)) = right(node);
                (right(node)) = NULL;
                (left(right(node_parent))) = node;
            }
        }
    }

    bool addNode(_Node *node)
    {
        _size++;
        if (empty())
        {
            _root = node;
            return true;
        }
        _Node *tmp = _root;
        while (tmp)
        {
            if (_ft_compare(key(tmp), key(node)))
            {
                if (!right(tmp))
                {
                    tmp->right = node;
                    return true;
                }
                tmp = right(tmp);
            }
            else if (!_ft_compare(key(tmp), key(node)))
            {
                if (!left(tmp))
                {
                    tmp->left = node;
                    return true;
                }
                tmp = left(tmp);
            }
            else
            {
                _size--;
                return false;
            }
        }
        return true;
    }
};

#endif