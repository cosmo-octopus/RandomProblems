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
}