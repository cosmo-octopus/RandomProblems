#include <iostream>
#include <string>

std::string to_hex(int num)
{
	std::string hex;

	for(int i = sizeof(int) * 2 - 1; i >= 0; --i)
	{
		int digit = (num >> (i * 4)) & 0xF; // same as decimal 15
		digit < 10 ? hex += '0' + digit : hex += 'A' + digit - 10;
	}
	return hex;
}

int	main()
{
	int num;

	std::cout << "Enter a number: ";
	while (std::cin >> num)
	{
		std::cout << "My result: " << to_hex(num) << std::endl;
		std::cout << "Automatic: " << std::hex << num << std::endl;
		std::cout << "Enter a number: ";
	}
}