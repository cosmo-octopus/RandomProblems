#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string  a, b;
    cin >> a >> b;
    
    cout << a.length() << " " << b.length() << endl;
    cout << a + b << endl;
    cout << b[0] << &a[1] << " " << a[0] << &b[1] << endl;
    
    return 0;
}