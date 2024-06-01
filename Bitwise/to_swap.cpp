#include <iostream>

void to_swap(int& first, int& second)
{
	if (first != second)
	{
		first = first ^ second;
		second = first ^ second;
		first = first ^ second;
	}
}

int	main()
{
	int first, second;

	std::cout << "Enter two numbers: ";

	while (std::cin >> first >> second)
	{
		to_swap(first, second);
		std::cout << "SWAPPED: first -> " << first << " second -> " << second << std::endl;
		std::cout << "Enter two numbers: ";
	}
}