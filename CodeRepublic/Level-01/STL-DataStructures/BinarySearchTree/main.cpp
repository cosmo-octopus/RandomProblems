#include "BinarySearchTree.h"

int	main()
{
	Tree<int>	tree;

	tree.addNode(42);
	tree.addNode(72);
	tree.addNode(12);
	tree.addNode(13);
	tree.addNode(7);
	tree.addNode(24);
	tree.addNode(2);
	tree.addNode(5);
	tree.printTree();
}