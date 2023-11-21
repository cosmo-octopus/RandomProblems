#include <iostream>

void	displayBinary(int number)
{
	int	bits[sizeof(int) * 8];

	for (int i = 0; i < sizeof(int) * 8; i++)
	{
		bits[i] = number & 1;
		number = number >> 1;
	}
	std::cout << "Binary representation: ";
	for (int i = sizeof(int) * 8 - 1; i >= 0; i--)
		std::cout << bits[i] << " ";
	std::cout << std::endl;
}

int	main()
{
	int	number;

	std::cout << "Enter a number: ";
	std::cin >> number;

	displayBinary(number);
}