#include <iostream>

bool checkRightLeftBitsEqual(int n)
{
    int bits = sizeof(n) * 8;
    int leftBit = n & (1 << (bits - 1));
    int rightBit = n & 1;

    return (leftBit == rightBit);
}

int main()
{
    int number1 = 17; // Example number with different left and right bits
    int number2 = 33; // Example number with same left and right bits

    std::cout << number1 << " has " << (checkRightLeftBitsEqual(number1) ? "different" : "equal") << " left and rightmost bits." << std::endl;
    std::cout << number2 << " has " << (checkRightLeftBitsEqual(number2) ? "different" : "equal") << " left and rightmost bits." << std::endl;

    return 0;
}