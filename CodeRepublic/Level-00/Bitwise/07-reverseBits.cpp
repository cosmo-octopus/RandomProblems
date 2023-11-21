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

void reverseBits(int n)
{
    int	bits = sizeof(int) * 8;
	int	reverse = 0;

	while (n)
	{
		reverse = reverse << 1;
		if (n & 1)
			reverse = reverse | 1;
		n = n >> 1;
	}
	n = reverse;
	displayBinary(n);
}

int main()
{
    int number = 240; // Example number: 11110000 in binary
	
	displayBinary(number);
    reverseBits(number);
}