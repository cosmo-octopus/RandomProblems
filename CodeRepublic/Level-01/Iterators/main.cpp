#include "Iterator.h"
#include "../Containers/Vector/Vector.h"

int	main()
{
	Vector<int>	vec;

	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	Iterator<int>	iter = vec.begin();
	std::cout << "dereference: " << *iter << std::endl;
	std::cout << "iter[3]: " << iter[3] << std::endl;
	// std::cout << "iter[10]: " << iter[10] << std::endl; // heap buffer overflow
	std::cout << std::endl;
	std::cout << "iterator++: " << *(iter++) << " " << *iter << std::endl;
	std::cout << "++iterator: " << *(++iter) << " " << *iter << std::endl;
	std::cout << std::endl;
	std::cout << "--iterator: " << *(--iter) << " " << *iter << std::endl;
	std::cout << "iterator--: " << *(iter--) << " " << *iter << std::endl;
}