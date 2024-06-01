#include <iostream>

int main()
{
	int num;

	std::cout << "Enter a number: ";

	while (std::cin >> num)
	{
		std::cout << num <<  " + 1 = " << -~num << std::endl;
		std::cout << "Enter a number: ";
	}
}