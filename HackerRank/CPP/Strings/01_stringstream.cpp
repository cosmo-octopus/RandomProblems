#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <sstream>

vector<int> parser(string str){
    stringstream    ss(str);
    vector<int>     vec;
    char            ch;
    int             n;
    
    while (ss >> n){
        vec.push_back(n);
        ss >> ch;
    }
    
    return vec;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string  str;
    cin >> str;
    
    vector<int> vec = parser(str);
    
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
    
    return 0;
}