#ifndef __BINARYSEARCHTREE_H__
# define __BINARYSEARCHTREE_H__

# include <limits>
# include <utility>
# include <iostream>
# include <stdexcept>

template <typename T>
class	Tree
{
	public:
		/* Node */
		class	Node
		{
			public:
				T		data;
				Node	*left;
				Node	*right;

				Node(void):	data(0), left(nullptr), right(nullptr){}
				Node(const T &data): data(data), left(nullptr), right(nullptr){}
		};
	
	private:
		Node	*root;
	
	public:
		Tree(void): root(nullptr){};
		Tree(const T &data);
		~Tree();

		void	destroyTree(Node *node);
		void	addNode(const T &data);
		void	printTree(void) const;

	private:
		void	printTree(typename Tree<T>::Node *node, int space) const;

};

# include "BinarySearchTree.hpp"

#endif