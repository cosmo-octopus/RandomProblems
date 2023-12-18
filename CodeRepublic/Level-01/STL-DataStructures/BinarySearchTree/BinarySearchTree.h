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
		void	graphical(void) const;
		bool	search(const T &value) const;
		void	inorder(void) const;
		void	preorder(void) const;
		void	postorder(void) const;

	private:
		void	destroy(Node *node);
		void	graphical(typename Tree<T>::Node* node, std::string prefix) const;
		bool	search(typename Tree<T>::Node *node, const T &value) const;
		void	inorder(Node *node) const;
		void	preorder(Node *node) const;
		void	postorder(Node *node) const;
};

// Իրականացնել Binary Search Tree ներառելով հետևյալ մեթոդները՝
// insert(value): Ծառում ավելացնել Value արժեքով node.
// delete(value): Ծառից հեռացնել value արժեքով node-ը.
// search(value): Փնտրել Value արժեքով node-ը և վերադարձնել 1 եթե կա, 0` հակառակ դեպքում.
// inorder(): Կատարել InOrder շրջանցում տպելով հանգույցների արժեքները (left, root, right).
// preorder(): Կատարել PreOrder շրջանցում տպելով հանգույցների արժեքները (root, left, right).
// postorder(): Կատարել PostOrder շրջանցում տպելով հանգույցների արժեքները (left, right, root).
// find_min(): Գտնել ծառի մինիմալ արժեքով node-ը և վերադարձնել.
// find_max(): Գտնել ծառի մաքսիմալ արժեքով node-ը և վերադարձնել.
// successor(value): Գտնել տրված value-ով node-ի successor node-ը և վերադարձնել.
// predecessor(value): Գտնել տրված value-ով node-ի predecessor node-ը և վերադարձնել.
// height(): Գտնել ծառի բարձրությունը և վերադարձնել.
// size(): Գտնել ծառի հանգույցների քանակը.
// is_valid_bst(): Վերադարձնել 1, եթե ծառը ճիշտ Բինար որոնման ծառ է ր 0` հակառակ դեպքում.
// print_tree(): Տպել ծառը հասկանալի տարբերակով։
// level_order(): Իրականացնել շրջանցում ըստ մակարդակների տպելով արժեքները.
// contains(value): Վերադարձնել 1, եթե ծառը ունի value արժեքով հանգույց և 0` հակառակ դեպքում։
// clear(): Ջնջել ծառի բոլոր հանգույցները
// serialize(): Ձևափոխել ծառի պարունակությունը ավելի հարմար տեսքի(array, string)
// range_query(start, end): Գտնել բոլոր հանգույցները տրված միջակայքի արժեքներով։
// copy(): Ստեղծել նոր ծառ, նույն կառուցվածքով և արժեքներով և վերադարձնել։
// kth_smallest(k): Գտնել և վերադարձնել k-րդ ամենափոքր էլեմենտը։
// kth_largest(k): Գտնել և վերադարձնել k-րդ ամենամեծ էլեմենտը։
// update(value, new_value): Նշված արժեքով հանգույցի արժեքը փոխել new-value-ով։

# include "BinarySearchTree.hpp"

#endif