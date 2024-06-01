#include <iostream>

int	main()
{
	int first, second;

	std::cout << "Enter two numbers: ";

	while (std::cin >> first >> second)
	{
		std::cout << "XOR RES: " << (first ^ second) << std::endl;
		if ((first ^ second) >= 0)
			std::cout << "SAME SIGN\n";
		else
			std::cout << "OPPOSITE SIGNS\n";

		std::cout << "Enter two numbers: ";
	}
}