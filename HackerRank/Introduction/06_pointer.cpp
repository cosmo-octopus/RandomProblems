#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void    change(int *a, int *b){
    int tmp;
    
    tmp = *a + *b;
    *b = abs(*a - *b);
    *a = tmp;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a, b;
    
    cin >> a;
    cin >> b;
    change(&a, &b);
    cout << a << endl;
    cout << b << endl;
    return 0;
}