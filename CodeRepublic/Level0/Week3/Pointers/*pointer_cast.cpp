/* PROBLEM: Write a void function named "foo"
with the following prototype:
void foo(int target, char c1, char c2, short sh)
This function will assign the values of "c1," "c2," and "sh"
variables in sequence to the "target" variable, which is of type int.*/

#include <iostream>
using namespace std;

void    foo(int *target, char c1, char c2, short sh)
{
    char    *c_ptr = (char *)target;
    short   *sh_ptr = NULL;

    *c_ptr = c1;
    *(c_ptr + 1) = c2;
    sh_ptr = (short *)(c_ptr + 2);
    *(sh_ptr) = sh;
}

int main()
{
    int     x = 5;
    int     *target = &x;
    char    c1 = '@', c2 = '$';
    short   sh = 2;

    foo(target, c1, c2, sh);
    
    char    *c_ptr = (char *)target;
    short   *sh_ptr = (short *)(c_ptr + 2);
    cout << *c_ptr << " " << *(c_ptr + 1) << " " << *(sh_ptr) << endl;
}