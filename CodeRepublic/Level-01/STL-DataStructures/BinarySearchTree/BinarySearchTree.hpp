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
	insert(this->root, value);
}

template <typename T>
void	Tree<T>::insert(typename Tree<T>::Node *&node, const T &value)
{
	if (!node)
	{
		node = new Node(value);
		return ;
	}

	if (value < node->value)
		insert(node->left, value);
	else if (value > node->value)
		insert(node->right, value);
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
        return (search(node->left, value));
    else
        return (search(node->right, value));
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
		preorder(node->left);
		preorder(node->right);
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
		postorder(node->left);
		postorder(node->right);
		if (node == this->root)
			std::cout << "[" << node->value << "]" << " ";
	}
}

template <typename T>
T	Tree<T>::find_min(void) const
{
	if (!this->root)
		std::cout << "Tree is empty" << std::endl;
	return (find_min(this->root));
}

template <typename T>
T	Tree<T>::find_min(typename Tree<T>::Node *node) const
{
	if (!node->left)
		return (node->value);
	return (find_min(node->left));
}

template <typename T>
T	Tree<T>::find_max(void) const
{
	if (!this->root)
		std::cout << "Tree is empty" << std::endl;
	return (find_max(this->root));
}

template <typename T>
T	Tree<T>::find_max(typename Tree<T>::Node *node) const
{
	if (!node->right)
		return (node->value);
	return (find_max(node->right));
}

template <typename T>
typename Tree<T>::Node	*Tree<T>::find(typename Tree<T>::Node *node, const T &value) const
{
	if (node->value == value)
		return (node);
	if (value < node->value)
		return (find(node->left, value));
	else
		return (find(node->right, value));
}

/* leftmost node of the right subtree*/
template <typename T>
T	Tree<T>::successor(const T &value) const
{
	Node	*node;

	if (!search(value))
		return (0);
	node = find(this->root, value);
	return (find_min(node->right));
}

/* rightmost node of the left subtree */
template <typename T>
T	Tree<T>::predecessor(const T &value) const
{
	Node	*node;

	if (!search(value))
		return (0);
	node = find(this->root, value);
	return (find_max(node->left));
}

template <typename T>
size_t	Tree<T>::height(void) const
{
	if (!this->root)
	{
		std::cout << "Tree is empty" << std::endl;
		return (0);
	}
	return (height(this->root));
}

template <typename T>
size_t	Tree<T>::height(const T &value) const
{
	Node	*node;

	if (!this->root)
	{
		std::cout << "Tree is empty" << std::endl;
		return (0);
	}
	node = find(this->root, value);
	return (height(node));
}

template <typename T>
size_t	Tree<T>::height(typename Tree<T>::Node *node) const
{
	size_t	left;
	size_t	right;

	if (!node)
		return (0);
	left = height(node->left);
	right = height(node->right);
	return (1 + std::max(left, right));
}

template <typename T>
size_t	Tree<T>::size(void) const
{
	if (!this->root)
	{
		std::cout << "Tree is empty" << std::endl;
		return (0);
	}
	return (size(this->root));
}

template <typename T>
size_t	Tree<T>::size(typename Tree<T>::Node *node) const
{
	int	left;
	int	right;

	if (!node)
		return (0);
	left = size(node->left);
	right = size(node->right);
	
	return (1 + left + right);
}

template <typename T>
bool	Tree<T>::valid(void) const
{
	if (!this->root)
	{
		std::cout << "Tree is empty" << std::endl;
		return (false);
	}
	return (valid(this->root));
}

template <typename T>
bool	Tree<T>::valid(typename Tree<T>::Node *node) const
{
	if (!node)
		return (true);
	if (node->left && node->left->value > node->value)
		return (false);
	if (node->right && node->right->value < node->value)
		return (false);
	return (valid(node->left) && valid(node->right));
}

template <typename T>
void	Tree<T>::level_order(void) const
{
	size_t	h;

	if (!this->root)
	{
		std::cout << "Tree is empty" << std::endl;
		return ;
	}
	h = height();
	for (size_t level = 0; level < h; level++)
	{
		std::cout << "level" << level << ": ";
		this_level(this->root, level);
		std::cout << std::endl;
	}
}

template <typename T>
void	Tree<T>::this_level(typename Tree<T>::Node *node, size_t level) const
{
	if (!node)
		return ;
	if (level == 0)
		std::cout << node->value << " ";
	else if (level > 0)
	{
		this_level(node->left, level - 1);
		this_level(node->right, level - 1);
	}
}

template <typename T>
void	Tree<T>::remove(const T &value)
{
	if (!this->root)
	{
		std::cout << "Tree is empty" << std::endl;
		return ;
	}
	remove(this->root, value);
}

template <typename T>
typename Tree<T>::Node	*Tree<T>::remove(typename Tree<T>::Node *node, const T &value)
{
	Node	*tmp;

    if (!node)
        return node;

    if (value < node->value)
        node->left = remove(node->left, value);
	else if (value > node->value)
        node->right = remove(node->right, value);
	else
	{
        if (!node->left)
		{
            tmp = node->right;
            delete node;
            return (tmp);
        }
		else if (!node->right)
		{
            tmp = node->left;
            delete node;
            return (tmp);
        }
		else
		{
            tmp = smallerNode(node->right);
            node->value = tmp->value;
            node->right = remove(node->right, tmp->value);
        }
    }
    return (node);
}

template <typename T>
typename Tree<T>::Node	*Tree<T>::smallerNode(typename Tree<T>::Node *node)
{
    if (!node)
        return nullptr;
    if (!node->left)
        return node;
    return smallerNode(node->left);
}

template <typename T>
T*	Tree<T>::serialise(void)
{
	size_t	h = height();
	size_t	s = size();
	int		i = 0;
	T		*data = new T[s];

	for (size_t level = 0; level < h; level++)
		this_level(this->root, level, data, i);
	return (data);
}

template <typename T>
void	Tree<T>::this_level(typename Tree<T>::Node *node, size_t level, T *data, int &i)
{
	if (!node)
		return ;
	if (level == 0)
		data[i++] = node->value;
	else if (level > 0)
	{
		this_level(node->left, level - 1, data, i);
		this_level(node->right, level - 1, data, i);
	}
}

template <typename T>
void	Tree<T>::range_query(const T &start, const T &end)
{
	range_query(this->root, start, end);
	std::cout << std::endl;
}

template <typename T>
void	Tree<T>::range_query(typename Tree<T>::Node *node, const T &start, const T &end)
{
	if (!node)
		return ;
	if (node->value >= start && node->value < end)
		std::cout << node->value << " ";
	if (node->value > start)
		range_query(node->left, start, end);
	if (node->value < end)
		range_query(node->right, start, end);
}

#endif