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
	std::cout << "dereferance: " << *iter << std::endl;
}