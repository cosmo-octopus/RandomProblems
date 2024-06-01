#include <iostream>

void	is_even(int num)
{
	if (num & 1)
	{
		std::cout << "NOT EVEN!" << std::endl;
		return ;
	}
	std::cout << "EVEN!" << std::endl;
}	


int	main()
{
	int num;

	std::cout << "Enter a number: ";
	
	while (std::cin >> num)
	{
		is_even(num);
		std::cout << "Enter a number: ";
	}

}