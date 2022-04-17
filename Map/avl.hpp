#ifndef _TREE_HPP
#define _TREE_HPP

#include "node.hpp"
#include "pair.hpp"

template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
struct Tree
{
public:
    // typedef const Key key_type;
    typedef Key key_type;
    typedef T mapped_type;
    typedef pair<const key_type, mapped_type> value_type;
    typedef Compare key_compare;
    typedef Alloc allocator_type;

    typedef Node<value_type> _Node;

    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;

    typedef typename Alloc::template rebind<Node<value_type> >::other node_allocator;
    typedef typename node_allocator::reference node_reference;
    typedef typename node_allocator::const_reference node_const_reference;
    typedef typename node_allocator::pointer node_pointer;
    typedef typename node_allocator::const_pointer node_const_pointer;

    typedef size_t size_type;

private:
    node_pointer _root;
    size_type _size;
    key_compare _ft_compare;
    allocator_type _allocator;
    node_allocator _node_allocator;

public:
    Tree() : _root(NULL), _size(0) {}
    ~Tree() {}

    allocator_type get_allocator() const { return _allocator; }

    node_pointer newNode(pointer p) 
    {
        node_pointer node = _node_allocator.allocate(1);
        _node_allocator.construct(node, _Node(p));
        return node;
    }

    pointer newPair(key_type k, mapped_type m) 
    {
        pointer p = _allocator.allocate(1);
        _allocator.construct(p, value_type(k, m));
        return p;
    }

    bool empty() const { return _root ? false : true; }

    node_pointer left(node_pointer node) const { return node->left; }

    node_pointer right(node_pointer node) const { return node->right; }

    key_type key(node_pointer node) { return node->content->first; }

    size_type size() const { return _size; }

    node_pointer root() const { return _root; }

    size_type height(node_pointer node) const
    {
        if (!node)
            return 0;
        size_type r = height(right(node));
        size_type l = height(left(node));

        return (r >= l ? r : l) + 1;
    }

    node_pointer search(key_type k)
    {
        node_pointer tmp = _root;
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

    node_pointer parent(node_pointer node) const
    {
        if (node == _root)
            return NULL;
        node_pointer tmp = _root;
        while (right(tmp) != node && left(tmp) != node)
        {
            if (!_ft_compare(key(tmp), key(node)))
                tmp = left(tmp);
            else
                tmp = right(tmp);
        }
        return tmp;
    }

    node_pointer rightRotation(node_pointer node)
    {
        node_pointer newParent = left(node);
        node->left = right(newParent);
        newParent->right = node;
        return newParent;
    }

    node_pointer leftRotation(node_pointer node)
    {
        node_pointer newParent = right(node);
        node->right = left(newParent);
        newParent->left = node;
        return newParent;
    }
    node_pointer rightRightCase(node_pointer node)
    { return leftRotation(node); }

    node_pointer rightLeftCase(node_pointer node)
    {
        node->right = rightRotation(node->right);
        return rightRightCase(node);
    }

    node_pointer leftLeftCase(node_pointer node)
    { return rightRotation(node); }

    node_pointer leftRightCase(node_pointer node)
    {
        node->left = leftRotation(node->left);
        return leftLeftCase(node);
    }

    node_pointer balance(node_pointer node)
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

    node_pointer insert(node_pointer node, pointer p)
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

    bool add(key_type first, mapped_type second)
    {
        if (search(first))
            return false;
        pointer p = newPair(first, second);
        _root = insert(_root, p);
        ++_size;
        return true;
    }

    // bool insert(pointer p)
    // {
    //     if (!p)
    //         return false;
    //     if (search(p->first))
    //         return false;
    //     _root = insert(_root, p);
    //     ++_size;
    //     return true;
    // }

    node_pointer smallestSuccessor(node_pointer node)
    {
        if (!left(node))
            return node;
        return smallestSuccessor(node->left);
    }

    void destroyPair(pointer p)
    {
        _allocator.destroy(p);
        _allocator.deallocate(p, 1);
    }
    void destroyNode(node_pointer node)
    {
        destroyPair(node->content);
        node->content = NULL;
        _node_allocator.destroy(node);
        _node_allocator.deallocate(node, 1);
    }

    node_pointer remove(node_pointer node, key_type &k)
    {
        if (key(node) == k)
        {
            if (!right(node) && !left(node))
            {
                // node with 0 childrens
                destroyNode(node);
                return NULL;
            }
            else if (right(node) && left(node))
            {
                // node with 2 childrens
                node_pointer small = smallestSuccessor(right(node));
                pointer tmp = node->content;
                node->content = small->content;
                small->content = tmp;
                node->right = remove(right(node), k);
                return node;
            }
            else // node with 1 childrens
            {
                node_pointer child = right(node) ? node->right : node->left;
                destroyNode(node);
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

    bool remove(key_type k)
    {
        if (!search(k))
            return false;
        _root = remove(_root, k);
        --_size;
        return true;
    }

    size_type max_size() const { return _node_allocator.max_size(); }

    mapped_type &change(key_type k, mapped_type m)
    {
        node_pointer node = search(k);
        if (!node)
            add(k, m);
        node = search(k);
        return node->content->second;
    }
    void test()
    {
        std::cout << std::boolalpha;
        std::cout << change(5, 10) << std::endl;
        int a = 0;
        while (a < 5)
        {
            printTree(_root, 0, a++);
            std::cout << std::endl;
        }
    }
};

#endif