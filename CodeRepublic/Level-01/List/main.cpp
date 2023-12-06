#include "List.h"

int	main()
{
	List<int>	list;

	list.push_back(42);
	list.push_back(42);
	list.push_back(42);
	list.push_back(42);

	list.list_print();

	// list.clear();
	// std::cout << "List has been cleared! Size: " << list.get_size() << std::endl;
	list.intert(0, 24);
	list.list_print();
	list.erase(0);
	list.erase(3);
	std::cout << "original list: ";
	list.list_print();
	List<int> list1;
	list1 = list;
	std::cout << "copied list: ";
	list1.list_print();
}