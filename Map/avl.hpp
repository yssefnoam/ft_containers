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
    
    size_type height(_Node *node)
    {
        if (!node)
            return 1;
        size_type right =  height(right(node));
        size_type left =  height(left(node));

        return (right >= left ? right : left) + 1;
    }

	size_type size() { return _size; }

	_Node *root() { return _root; }

	_Node* search(key_type k)
    {
        _Node *tmp = _root;
        while(tmp)
        {
		std::cout << k << std::endl;
            if (key(tmp) == k)
                return tmp;
            if (_ft_compare(k, key(tmp)))
                tmp = left(tmp);
            else
                tmp = right(tmp);
        }
        return NULL;
    }

	_Node* parent(_Node *node)
	{
		if (empty() || size() == 1)
			return NULL;

        _Node *tmp = _root;
        while(right(tmp) != node && left(tmp) != node)
        {
            if (_ft_compare(key(node), key(tmp)))
                tmp = left(tmp);
            else
                tmp = right(tmp);
        }
        return tmp;

	}

    bool	insertNode(_Node *node)
	{
		bool	rightOrLeft = false;

		if(search(key(node)))
			return false;
		_size++;
		if (empty())
		{
			_root = node;
			return true;
		}
        _Node *tmpChild = _root;
        _Node *tmpParent = NULL;
        while(tmpChild)
        {
            if (_ft_compare(key(node), key(tmpChild)))
			{
				rightOrLeft = true;
				tmpParent = tmpChild;
                tmpChild = left(tmpChild);
			}
			else
			{
				rightOrLeft = false;
				tmpParent = tmpChild;
                tmpChild = right(tmpChild);
			}
        }
		rightOrLeft ? tmpParent->right = node : tmpParent->left = node;
		return true;
	}
};

#endif