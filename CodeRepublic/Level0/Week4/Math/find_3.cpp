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