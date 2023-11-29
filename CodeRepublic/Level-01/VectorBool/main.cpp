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
	std::cout << vec.At(0) << std::endl;
	std::cout << vec.At(1) << std::endl;
	std::cout << vec.At(2) << std::endl;
	std::cout << vec.At(3) << std::endl;
	std::cout << vec.At(4) << std::endl;
	std::cout << vec.At(5) << std::endl;
	std::cout << vec.At(6) << std::endl;

	vec.At(0) = false;
	vec.print();

	// vec1.push_back(true);
	// vec1.push_back(false);
	// vec1.push_back(true);
	// vec1.push_back(false);
	// vec1.push_back(true);
	// vec1.pop_back();

	// std::cout << vec.at(4) << std::endl;
	// std::cout << vec1.at(4) << std::endl;

}