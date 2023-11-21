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

 void	reset(int n, int i)
 {
	i--;
	int	mask = 1 << i;

	n = n & (~mask);
	std::cout << i << "-th bit resetted: ";
	displayBinary(n);
 }

int	main()
{
	int	number;

	std::cout << "Enter a number: ";
	std::cin >> number;

	displayBinary(number);
	reset(number, 3);
}