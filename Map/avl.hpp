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
        _Node *newParent = left(node);
        node->left = right(newParent);
        newParent->right = node;
        return newParent;
    }

    _Node *leftRotation(_Node *node)
    {
        _Node *newParent = right(node);
        node->right = left(newParent);
        newParent->left = node;
        return newParent;
    }
    _Node *rightRightCase(_Node *node)
    {
        return leftRotation(node);
    }

    _Node *rightLeftCase(_Node *node)
    {
        node->right = rightRotation(node->right);
        return rightRightCase(node);
    }

    _Node *leftLeftCase(_Node *node)
    {
        return rightRotation(node);
    }

    _Node *leftRightCase(_Node *node)
    {
        node->left = leftRotation(node->left);
        return leftLeftCase(node);
    }
    

    _Node* balance(_Node *node)
    {
        int rh = height(node->right);
        int lh = height(node->left);

        if (rh - lh > 1) // left rotation
        {
            rh = height(node->right->right);
            lh = height(node->right->left);
            if (rh - lh >= 0)
                return rightRightCase(node);
            else
                return rightLeftCase(node);
        }
        else if (rh - lh < -1) // right rotation
        {
            rh = height(node->left->right);
            lh = height(node->left->left);
            if (rh - lh <= 0)
                return leftLeftCase(node);
            else
                return leftRightCase(node);
        }
        return node;
    }

    _Node *insert(_Node *node, value_type *p)
    {
        if (node == NULL)
            return newNode(p);

        if (_ft_compare(key(node), p->first))
            node->right = insert(node->right, p);
        else
            node->left = insert(node->left, p);
        node = balance(node);
        return node;
    }

    bool insert(value_type *p)
    {
        if (!p)
            return false;
        if (search(p->first))
            return false;
        _root = insert(_root, p);
        ++_size;
        return true;
    }

    _Node *smallestSuccessor(_Node *node)
    {
        if (!left(node))
            return node;
        return smallestSuccessor(node->left);
    }

    _Node *remove(_Node *node, key_type &k)
    {
        if (key(node) == k)
        {
            if (!right(node) && !left(node))
            {
                // node with 0 childrens
                // delete node
                return NULL;
            }
            else if (right(node) && left(node))
            {
                // node with 2 childrens
                _Node *small = smallestSuccessor(right(node));
                value_type *tmp = node->content;
                node->content = small->content;
                small->content = tmp;
                node->right = remove(right(node), k);
                return node;
            }
            else // node with 1 childrens
            {
                _Node *child = right(node) ? node->right : node->left;
                // delete node
                return child;
            }
        }
        if (_ft_compare(key(node), k))
            node->right = remove(node->right, k);
        else
            node->left = remove(node->left, k);

        node = balance(node);
        return node;
    }

    bool remove(key_type &k)
    {
        if (!search(k))
            return false;
        _root = remove(_root, k);
        --_size;
        return true;
    }

    bool change(key_type k, mapped_type newValue)
    {
        _Node* node = search(k);
        if (!node)
            return false;
        node->content->second = newValue;
        return true;
    }
    void test()
    {
        std::cout << std::boolalpha;
        std::cout << change(5,10) << std::endl;
        int a = 0;
        while(a<5)
        {
            printTree(_root, 0, a++);
            std::cout << std::endl;
        }
    }
};

#endif