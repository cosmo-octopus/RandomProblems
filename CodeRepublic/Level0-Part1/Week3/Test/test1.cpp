#include <iostream>
using namespace std;

int foo(int *ptr, int *ptr1)
{
    *ptr += 1;
    *ptr1 = *ptr;

    return (++*ptr1);
}

int main()
{
    int a = 2;
    int b = 4;
    int c = foo(&a, &a);

    cout << a << b << c << endl;
}
