/* PROBLEM: Implement <cstring> strchr recursively.
(Returns a pointer to the first occurrence
of character in the C string str.) */

#include <iostream>
using namespace std;

const char    *ft_strchr(const char *str, const char c)
{
    if (*str && *(str) != c)
        return (ft_strchr(++str, c));
    return (str);
}

int main()
{
    const char  *str = "Hello you, traveler!";
    const char  c = ',';
    cout << (void*)ft_strchr(str, c) << '\n';
    cout << *(ft_strchr(str, c)) << endl;
}