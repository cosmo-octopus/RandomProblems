/* PROBLEM: Write a program, using only
the main function and without using any
loops or additional functions, to print the
numbers from 1 to 20.*/

/* !!! TLDR: Calling main results in undefined behavior.

Any program that calls main() exhibits undefined behavior
(technically, such a program is ill-formed because the rule
being violated is a diagnosable semantic rule). */

#include <iostream>
using namespace std;

int main()
{
    static int count = 0;
    count++;
    if(count <= 20)
    {
        cout << count<< " ";
        return main();
    }
    cout << endl;
    // system("pause");
    return 0;
}