/* PROBLEM: Write a program that determines
whether the digit '3' is present in a given
integer 'num.' The program should return true (1)
if '3' is found in the number and false (0) otherwise. */

#include <iostream>
using namespace std;

bool    find_3(int num);

int main()
{
    cout << find_3(54545) << endl;
}

bool    find_3(int num)
{
    while (num)
    {
        if (num % 10 == 3)
            return (1);
        num /= 10;
    }
    return (0);
}