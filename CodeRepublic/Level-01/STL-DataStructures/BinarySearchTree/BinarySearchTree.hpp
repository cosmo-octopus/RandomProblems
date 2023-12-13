#ifndef __BINARYSEARCHTREE_HPP__
# define __BINARYSEARCHTREE_HPP__

# include "BinarySearchTree.h"

template <typename T>
void	Tree<T>::destroyTree(typename Tree<T>::Node *node)
{
	if (node)
	{
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
	}
}

template <typename T>
Tree<T>::~Tree()
{
	destroyTree(this->root);
	this->root = nullptr;
}

template <typename T>
void	Tree<T>::addNode(const T &data)
{
	Node	*node = new Node(data);
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
        if (data > runner->data)
            runner = runner->right;
        else if (data < runner->data)
            runner = runner->left;
        else
		{
            delete node;
            return;
        }
    }
    if (data > prev->data)
        prev->right = node;
    else
        prev->left = node;
}

template <typename T>
void	Tree<T>::printTree(typename Tree<T>::Node *node, int space) const
{
	if (!node)
		return ;
	space += 5;
	printTree(node->right, space);
	std::cout << std::endl;
	for (int i = 5; i < space; i++)
	{
		std::cout << " ";
	}
	std::cout << "[" << node->data << "]" << "\n";
	printTree(node->left, space);
}

template <typename T>
void	Tree<T>::printTree(void) const
{
	if (!this->root)
		throw std::out_of_range("Tree is empty");
	printTree(this->root, 0);
}

#endif