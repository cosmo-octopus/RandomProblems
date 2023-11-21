#include <iostream>

// bool isPowerOfFour(int n)
// {
//     // Check if the number is a power of 2 and the only set bit is in an even position
//     return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
// }

bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false; // 0 and negative numbers are not powers of 2
    return ((n & (n - 1)) == 0);
}

int main()
{
    int number1 = 16;
    int number2 = 15;

    std::cout << number1 << " is " << (isPowerOfTwo(number1) ? "a power of 2" : "not a power of 2") << std::endl;
    std::cout << number2 << " is " << (isPowerOfTwo(number2) ? "a power of 2" : "not a power of 2") << std::endl;
}