#ifndef __BINARYSEARCHTREE_HPP__
# define __BINARYSEARCHTREE_HPP__

# include "BinarySearchTree.h"

template <typename T>
void	Tree<T>::destroy(typename Tree<T>::Node *node)
{
	if (node)
	{
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}

template <typename T>
Tree<T>::~Tree()
{
	destroy(this->root);
	this->root = nullptr;
}

template <typename T>
void	Tree<T>::insert(const T &value)
{
	Node	*node = new Node(value);
    Node	*runner = this->root;
    Node	*prev = nullptr;

    if (!runner)
	{
        this->root = node;
        return;
    }
    while (runner)
	{
        prev = runner;
        if (value > runner->value)
            runner = runner->right;
        else if (value < runner->value)
            runner = runner->left;
        else
		{
            delete node;
            return;
        }
    }
    if (value > prev->value)
        prev->right = node;
    else
        prev->left = node;
}

template<typename T>
void Tree<T>::graphical(void) const
{
    if (!this->root)
	{
        std::cout << "The tree is empty." << std::endl;
        return ;
    }
    graphical(root, "");
}

template<typename T>
void Tree<T>::graphical(typename Tree<T>::Node* node, std::string prefix) const
{
    constexpr int spacing = 5;

    if (!node)
        return ;
    graphical(node->right, prefix + std::string(spacing, ' '));
    std::cout << prefix << "|-- " << node->value << std::endl;
    graphical(node->left, prefix + std::string(spacing, ' '));
}

template <typename T>
bool	Tree<T>::search(const T &value) const
{
	if (!this->root)
	{
		std::cout << "Tree is empty" << std::endl;
		return (false);
	}
	return (search(this->root, value));
}

template <typename T>
bool	Tree<T>::search(typename Tree<T>::Node *node, const T &value) const
{
	if (!node)
        return (false);

    if (node->value == value)
        return true;
    if (value < node->value)
        return search(node->left, value);
    else
        return search(node->right, value);
}

template <typename T>
void	Tree<T>::inorder(void) const
{
	if (!this->root)
		std::cout << "Tree is empty" << std::endl;
	inorder(this->root);
	std::cout << std::endl;
}

template <typename T>
void	Tree<T>::inorder(typename Tree<T>::Node *node) const
{
	if (node)
	{
		inorder(node->left);
		if (node == this->root)
			std::cout << "[" << node->value << "]" << " ";
		else
			std::cout << node->value << " ";
		inorder(node->right);
	}
}

template <typename T>
void	Tree<T>::preorder(void) const
{
	if (!this->root)
		std::cout << "Tree is empty" << std::endl;
	preorder(this->root);
	std::cout << std::endl;
}

template <typename T>
void	Tree<T>::preorder(typename Tree<T>::Node *node) const
{
	if (node)
	{
		if (node == this->root)
			std::cout << "[" << node->value << "]" << " ";
		else
			std::cout << node->value << " ";
		inorder(node->left);
		inorder(node->right);
	}
}

template <typename T>
void	Tree<T>::postorder(void) const
{
	if (!this->root)
		std::cout << "Tree is empty" << std::endl;
	postorder(this->root);
	std::cout << std::endl;
}

template <typename T>
void	Tree<T>::postorder(typename Tree<T>::Node *node) const
{
	if (node)
	{
		if (node != this->root)
			std::cout << node->value << " ";
		inorder(node->left);
		inorder(node->right);
		std::cout << "[" << node->value << "]" << " ";
	}
}

#endif