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
	std::cout << "minimum: " << tree.find_min() << std::endl;
	std::cout << "maximum: " << tree.find_max() << std::endl;
	std::cout << "successor of 42: " << tree.successor(42) << std::endl;
	std::cout << "predecessor of 42: " << tree.predecessor(42) << std::endl;
	std::cout << "tree height: " << tree.height() << std::endl;
	std::cout << "tree size: " << tree.size() << std::endl;
	std::cout << "is my binary search tree valid: " << tree.valid() << std::endl;
	std::cout << "tree by levels: " << std::endl;
	tree.level_order();
	std::cout << "find height for 13: " << tree.height(13) << std::endl;
	tree.remove(12);
	tree.graphical();
	int	*arr = tree.serialise();
	int	s = tree.size();
	for (int i = 0; i < s; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	delete [] arr;
	tree.range_query(5, 40);
	// std::cout << "copy constructor check:" << std::endl;
	// Tree<int>	other(tree);
	// other.graphical();
	std::cout << "4th smallest element: " << tree.kth_smallest(4) << std::endl;
	std::cout << "9th smallest element: " << tree.kth_smallest(9) << std::endl;
	std::cout << "4th largest element: " << tree.kth_largest(4) << std::endl;
}