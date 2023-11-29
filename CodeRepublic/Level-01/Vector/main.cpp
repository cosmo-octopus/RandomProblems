#include "Vector.h"

int	main()
{
	Vector<int>	vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	std::cout << vec.get_size() << " " << vec.get_capacity() << std::endl;
	vec.print();
	vec.resize(2);
	vec.print();
	std::cout << vec.get_size() << " " << vec.get_capacity() << std::endl;
	vec.shrink_to_fit();
	std::cout << vec.get_size() << " " << vec.get_capacity() << std::endl;
	vec.push_back(7);

	vec.print();
	vec.clear();

	vec.assign(3, 6);
	vec.print();
	vec.pop_back();
	vec.print();
	vec.insert(2, 0);
	vec.print();
	vec.assign(7, 7);
	vec.print();
	vec.erase(0);
	vec.erase(2, 5);
	vec.print();
	
	Vector<int> vec1;
	vec1.assign(3, 3);
	vec.swap(vec1);
	vec.print();
	vec.emplace(1, 42);
	vec.print();

	Vector<int>	vec2(3, 10);
	// vec2.print();
	std::cout << vec2 << std::endl;

	Vector<int> vecCpy(std::move(vec2));
	vecCpy.print();
	vec2.print();

	vec2 = vecCpy;
	vec2.print();

	vec2 = std::move(vecCpy);

	vecCpy.print();
	vec2.print();
	vec2.emplace_back(42);
	vec2.print();
}