#include <iostream>

int	countOnes(int number)
{
	int	counter = 0;

	while (number)
	{
		counter += number & 1;
		number = number >> 1;
	}
	return (counter);
}

void displayBinary(int number)
{
    int bits[sizeof(int) * 8]; // Assuming an integer is 32 bits

    for (int i = 0; i < sizeof(int) * 8; ++i)
	{
        bits[i] = number & 1;
        number = number >> 1;
    }
    std::cout << "Binary representation: ";
    for (int i = sizeof(int) * 8 - 1; i >= 0; --i)
        std::cout << bits[i];
    std::cout << std::endl;
}

int	main()
{
	int	number;

	std::cout << "Enter a number: ";
	std::cin >> number;

	displayBinary(number);

	std::cout << "number of ones in the binary representation of " << number <<
	" is: " << countOnes(number) << std::endl;
}