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
            if (_ft_compare(key(tmp), k))
                tmp = right(tmp);
            else
                tmp = left(tmp);
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

    _Node *rightRotation(_Node *node)
    {
        _Node *child = left(node);
        node->left = NULL;
        child->right = node;
        return child;
    }

    _Node *leftRotation(_Node *node)
    {
        _Node *child = right(node);
        node->right = NULL;
        child->left = node;
        return child;
    }

    void rotate(_Node *node)
    {
        int rhs = height(node->right);
        int lhs = height(node->left);

        if (rhs - lhs > 1) // left rotation
        {
        }
        else if (rhs - lhs < -1) // right rotation
        {
        }
    }

    _Node *insertNode(_Node *node, value_type *p)
    {
        if (node == NULL)
            return newNode(p);

        if (_ft_compare(key(node), p->first))
            node->right = insertNode(node->right, p);
        else
            node->left = insertNode(node->left, p);
        
        rotate(node);

        return node;
    }

    bool insert(value_type *p)
    {
        if (!p)
            return false;
        if (search(p->first))
            return false;
        _root = insertNode(_root, p);
        ++_size;
        return true;
    }
    void test()
    {
        // _root = leftRotation(_root);
        _root = rightRotation(_root);
    }
    // bool addNode(_Node *node)
    // {
    //     _size++;
    //     if (empty())
    //     {
    //         _root = node;
    //         return true;
    //     }
    //     _Node *tmp = _root;
    //     while (tmp)
    //     {
    //         if (_ft_compare(key(tmp), key(node)))
    //         {
    //             if (!right(tmp))
    //             {
    //                 tmp->right = node;
    //                 // TODO: calculate height and retate if needed
    //                 return true;
    //             }
    //             tmp = right(tmp);
    //         }
    //         else if (!_ft_compare(key(tmp), key(node)))
    //         {
    //             if (!left(tmp))
    //             {
    //                 tmp->left = node;
    //                 return true;
    //             }
    //             tmp = left(tmp);
    //         }
    //         else
    //         {
    //             _size--;
    //             return false;
    //         }
    //     }
    //     return true;
    // }
};

#endif