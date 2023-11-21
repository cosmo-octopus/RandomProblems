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

void	swapBitPos(int n, int i, int j)
{
	i--;
	j--;
	int	mask = 0;

	if (((n >> i) & 1) != ((n >> j) & 1))
	{
		mask = (1 << i) | (1 << j);
		n = n ^ mask;
	}
	displayBinary(n);
}

int	main()
{
	int	number;

	std::cout << "Enter a number: ";
	std::cin >> number;

	displayBinary(number);
	swapBitPos(number, 3, 5);
}