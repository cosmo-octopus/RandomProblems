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
				T		value;
				Node	*left;
				Node	*right;

				Node(void):	value(0), left(nullptr), right(nullptr){}
				Node(const T &value): value(value), left(nullptr), right(nullptr){}
		};
	
	private:
		Node	*root;
	
	public:
		Tree(void): root(nullptr){};
		Tree(const T &value);
		~Tree();

		void	insert(const T &value);
		void	graphical(void) const; /* prints the tree in a graphical way */
		bool	search(const T &value) const;
		void	inorder(void) const; /* left, root, right */
		void	preorder(void) const; /* root, left, right */
		void	postorder(void) const; /* left, right, root */
		T		find_min(void) const;
		T		find_max(void) const;
		T		successor(const T &value) const;
		T		predecessor(const T &value) const;
		size_t	height(void) const;
		size_t	height(const T &value) const;
		size_t	size(void) const;
		bool	valid(void) const;
		void	level_order(void) const; /* prints the tree by levels */
		void	remove(const T &value);
		T*		serialise(void);
		void	range_query(const T &start, const T &end);

	private:
		void	insert(typename Tree<T>::Node *&node, const T &value);
		void	destroy(Node *node);
		void	graphical(typename Tree<T>::Node* node, std::string prefix) const;
		bool	search(typename Tree<T>::Node *node, const T &value) const;
		void	inorder(Node *node) const;
		void	preorder(Node *node) const;
		void	postorder(Node *node) const;
		T		find_min(Node *node) const;
		T		find_max(Node *node) const;
		Node	*find(Node *node, const T &value) const;
		size_t	height(Node *node) const;
		size_t	size(Node *node) const;
		bool	valid(Node	*node) const;
		void	this_level(Node *node, size_t level) const;
		Node	*smallerNode(Node *node);
		Node	*remove(Node *node, const T &value);
		void	this_level(Node *node, size_t level, T *data, int &i);
		void	range_query(Node *node, const T &start, const T &end);
};

// copy(): Ստեղծել նոր ծառ, նույն կառուցվածքով և արժեքներով և վերադարձնել։
// kth_smallest(k): Գտնել և վերադարձնել k-րդ ամենափոքր էլեմենտը։
// kth_largest(k): Գտնել և վերադարձնել k-րդ ամենամեծ էլեմենտը։
// update(value, new_value): Նշված արժեքով հանգույցի արժեքը փոխել new-value-ով։

# include "BinarySearchTree.hpp"

#endif