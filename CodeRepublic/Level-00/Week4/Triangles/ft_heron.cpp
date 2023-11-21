/* PROBLEM: Write a program that calculates
the area of a triangle using the Heron's formula,
provided the lengths of its three sides.
The program should also determine if the given
side lengths form a valid triangle. If the sides
do not constitute a valid triangle, the program
should output "FALSE"; otherwise, it should display
"TRUE" along with the computed area of the triangle. */

#include <iostream>
using namespace std;

int ft_root(int num)
{
    int res = 0;
    int i = 0;

    while (1)
    {
        res = i * i;
        if (res == num)
            return (i);
        if (res > num)
            return (i - 1);
        i++;
    }
    return (-1);
}

int ft_heron(int a, int b, int c)
{
    int sp = (a + b + c) / 2; //semiperimeter
    int area = ft_root(sp * (sp - a) * (sp - b) * (sp - c));

    return (area);
}

bool    is_triangle(int a, int b, int c)
{
    if (a + b > c && a + c > b && b + c > a)
        return (true);
    return (false);
}

int main()
{
    int a = 0, b = 0, c = 0;

    cout << "Side a: ";
    cin >> a;
    cout << "Side b: ";
    cin >> b;
    cout << "Side c: ";
    cin >> c;

    if (is_triangle(a, b, c))
        cout << "TRUE: S = " << ft_heron(a, b, c) << endl;
    else
        cout << "FALSE\n";
}