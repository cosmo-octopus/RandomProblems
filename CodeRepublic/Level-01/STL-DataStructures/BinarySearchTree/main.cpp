#include "BinarySearchTree.h"

int	main()
{
	Tree<int>	tree;

	tree.insert(42);
	tree.insert(72);
	tree.insert(12);
	tree.insert(13);
	tree.insert(7);
	tree.insert(24);
	tree.insert(2);
	tree.insert(5);
	tree.insert(41);
	tree.insert(44);
	tree.graphical();

	std::cout << "search for 2: " << tree.search(2) << std::endl;
	std::cout << "search for 100: " << tree.search(100) << std::endl;
	std::cout << "inorder: ";
	tree.inorder();
	std::cout << "preorder: ";
	tree.preorder();
	std::cout << "postorder: ";
	tree.postorder();
}