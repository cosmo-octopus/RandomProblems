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
	vec.push_back(false);

	vec1.push_back(true);
	vec1.push_back(false);
	vec1.push_back(true);
	vec1.push_back(false);
	vec1.push_back(true);
	vec1.push_back(false);

	std::cout << vec.at(5) << std::endl;
	std::cout << vec1.at(5) << std::endl;

}