#include "Vector.hpp"

int	main()
{
	Vector<int>	vec;

	vec.push_back(10);
	vec.vec_print();
	std::cout << vec.get_size() << " " << vec.get_capacity() << std::endl;
}