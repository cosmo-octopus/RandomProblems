#include "List.h"

int	main()
{
	List<int>	list;

	// list.push_back(42);
	// list.push_back(42);
	// list.push_back(42);
	// list.push_back(42);

	// list.list_print();

	// list.clear();
	// std::cout << "List has been cleared! Size: " << list.get_size() << std::endl;
	// list.intert(0, 24);
	// list.list_print();
	// list.erase(0);
	// list.erase(3);
	// // std::cout << "original list: ";
	// list.list_print();
	// std::cout << "current list size: " << list.get_size() << std::endl;
	// // List<int> list1;
	// // list1 = list;
	// // std::cout << "copied list: ";
	// // list1.list_print();
	// list.pop_back();
	// list.list_print();
	// std::cout << "current list size: " << list.get_size() << std::endl;
	// list.push_front(24);
	// list.list_print();
	// std::cout << "current list size: " << list.get_size() << std::endl;
	// list.pop_front();
	// list.list_print();
	// std::cout << "current list size: " << list.get_size() << std::endl;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	// list.push_back(42);
	list.list_print();
	// list.unique();
	// list.list_print();
	List<int> list1;
	list1.push_back(0);
	list1.push_back(5);
	list1.push_back(12);
	std::cout << "List1: ";
	list.list_print();
	std::cout << "List2: ";
	list1.list_print();

	list.merge(list1);
	std::cout << "Merge: ";
	list.list_print();
}