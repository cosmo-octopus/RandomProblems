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

	private:
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
};

// delete(value): Ծառից հեռացնել value արժեքով node-ը.
// clear(): Ջնջել ծառի բոլոր հանգույցները
// serialize(): Ձևափոխել ծառի պարունակությունը ավելի հարմար տեսքի(array, string)
// range_query(start, end): Գտնել բոլոր հանգույցները տրված միջակայքի արժեքներով։
// copy(): Ստեղծել նոր ծառ, նույն կառուցվածքով և արժեքներով և վերադարձնել։
// kth_smallest(k): Գտնել և վերադարձնել k-րդ ամենափոքր էլեմենտը։
// kth_largest(k): Գտնել և վերադարձնել k-րդ ամենամեծ էլեմենտը։
// update(value, new_value): Նշված արժեքով հանգույցի արժեքը փոխել new-value-ով։

# include "BinarySearchTree.hpp"

#endif