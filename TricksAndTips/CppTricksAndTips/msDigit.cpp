/* Calculating the most significant digit:
* To calculate the most significant digit
* of any number log can be directly used to calculate it.
* We can calculate the number of digits and then
* divide the number by 10^(number of digits-1) */

#include <iostream>
#include <cmath>

int msDigit(int num)
{
    int digit = log10(num); // number of digits in a number=log10(N)+1
    int x = pow(10, digit);

    if (num == 0)
        return (0);
    return (num/x);
}

int main()
{
    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "The most significant digit is: " << msDigit(num) << std:: endl;
}