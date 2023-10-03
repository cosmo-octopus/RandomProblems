#include <iostream>

// Multiply n with 2
// n = n << 1;
// Divide n by 2
// n = n >> 1;

int main()
{
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (num & 1)
        std::cout << "Odd" << std::endl;
    else
        std::cout << "Even" << std::endl;
}