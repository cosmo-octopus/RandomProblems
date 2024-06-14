#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct  Struct{
    int     age;
    string  name;
    string  last_name;
    int     standard;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Struct  student;
    
    cin >> student.age >> student.name >> student.last_name >> student.standard;
    cout << student.age << " " << student.name << " " << student.last_name << " " 
        << student.standard << endl;
       
    return 0;
}
