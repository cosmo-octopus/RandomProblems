#include "Vector.hpp"

int	main()
{
	Vector<int>	vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	std::cout << vec.get_size() << " " << vec.get_capacity() << std::endl;

	vec.vec_print();
	vec.resize(2);
	vec.vec_print();
	std::cout << vec.get_size() << " " << vec.get_capacity() << std::endl;
	vec.shrink_to_fit();
	std::cout << vec.get_size() << " " << vec.get_capacity() << std::endl;
}