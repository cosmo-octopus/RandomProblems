/* PROBLEM:  Implement <cstring> strstr.
(Finds the first occurrence of a substring
within a given C-style (null-terminated) string
and returns a pointer to the first character of
the found substring within the input string or
a null pointer if the substring is not found.) */

#include <iostream>
using namespace std;

// const char  *ft_strstr(const char *haystack, const char *needle)
// {
//     int			i, j;
//     const char	*ptr = NULL;

//     while (*(haystack + i))
//     {
//         if (*(haystack + i) == *(needle + j))
//         {
//             ptr = haystack + i;
//             while (haystack[i++] == *(needle + j))
//                 j++;
//             if (!*(needle + j))
//                 return (ptr);
//             else
//                 j = 0;
//         }
//         i++;
//     }
//     return (nullptr);
// }

const char  *ft_strstr(const char *haystack, const char *needle)
{
    int i, j;
    const char  *ptr = NULL;

    while (*(haystack + i))
    {
        if (*(haystack + i) == *(needle + j))
            j++;
        if (!*(needle + j))
            return (haystack + i - --j);
        if (*(haystack + i) != *(needle + (j - 1)))
            j = 0;
        i++;
    }
    return (nullptr);
}

int main()
{
    const char  *haystack = "hel lllhsh world";
    const char  *needle = "llhsh";

    cout << ft_strstr(haystack, needle) << endl;
}