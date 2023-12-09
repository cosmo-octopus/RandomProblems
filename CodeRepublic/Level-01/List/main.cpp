#include "List.h"

int	main()
{
	List<int>	list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.list_print();

	List<int> list1;
	list1.push_back(0);
	list1.push_back(12);
	list1.push_back(5);
	list1.push_back(42);
	list1.push_back(3);
	list1.list_print();
	std::cout << "sorted: ";
	list1.sort();
	list1.list_print();
	std::cout << "list 1: ";
	list.list_print();
	std::cout << "list 2: ";
	list1.list_print();

	list.swap(list1);
	std::cout << "swap" << std::endl;
	std::cout << "list 1: ";
	list.list_print();
	std::cout << "list 2: ";
	list1.list_print();

	list.merge(list1);
	std::cout << "merge: ";
	list.list_print();
	std::cout << "final size: " << list.get_size() << std::endl;
	list.reverse();
	std::cout << "reversed list: ";
	list.list_print();
}