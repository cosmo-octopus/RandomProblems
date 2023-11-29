#include "VectorBool.h"
#include <vector>

int	main()
{
	VectorBool			vec;
	std::vector<bool>	vec1;

	vec.push_back(true);
	vec.push_back(false);
	vec.push_back(true);
	vec.push_back(false);
	vec.push_back(true);
	vec.print();
	vec.pop_back();
	vec.print();
	vec.resize(7);
	vec.print();
	std::cout << vec.at(0) << std::endl;
	std::cout << vec.at(1) << std::endl;
	std::cout << vec.at(2) << std::endl;
	std::cout << vec.at(3) << std::endl;
	std::cout << vec.at(4) << std::endl;
	std::cout << vec.at(5) << std::endl;
	std::cout << vec.at(6) << std::endl;

	vec.at(0) = false;
	vec.print();
	std::cout << vec << std::endl;

}