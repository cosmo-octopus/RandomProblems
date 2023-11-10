#include <iostream>

int	countOnesBinary(int number)
{
	int	counter = 0;

	while (number)
	{
		counter += number & 1;
		number = number >> 1;
	}
	return (counter);
}

int	main()
{
	int	number;

	std::cout << "Enter a number: ";
	std::cin >> number;

	if (countOnesBinary(number) % 2)
		std::cout << "Number of ones in the binary representation of the number is odd" \
		<< std::endl;
	else
		std::cout << "Number of ones in the binary representation of the number is even" \
		<< std::endl;
}