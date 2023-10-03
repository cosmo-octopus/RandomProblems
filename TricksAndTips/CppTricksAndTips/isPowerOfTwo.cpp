/* Time complexity: O(v)
* where v is the number of digits of the number in binary form. */

#include <iostream>

bool isPowerOfTwo (int x)
{
    /* First x in the below expression is
    for the case when x is 0 */
    return (x && (!(x & (x - 1))));
}

int main()
{
    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;
    isPowerOfTwo(num) ? std::cout << "Yes" << std::endl
                        : std::cout << "No" << std::endl;
}