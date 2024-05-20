#include <iostream>
#include <string>
#include <algorithm>

std::string	to_binary(int num)
{
	std::string binary;

	while (num)
	{
		binary += '0' + (num & 1);
		num >>= 1;
	}
	std::reverse(binary.begin(), binary.end());
	return binary;
}

int	main()
{
	int num;

	std::cout << "Enter a number: ";
	std::cin >> num;

	std::cout << "Binary representation: " << to_binary(num) << std::endl;
}