#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m_size;
    cin >> m_size;
    int query;
    cin >> query;
    
    vector<vector<int>>   m;
    m.reserve(m_size);
    
    for (int i = 0; i < m_size; i++){
        int size;
        cin >> size;
        m[i].reserve(size);
        for (int j = 0; j < size; j++)
            cin >> m[i][j];
    }
    while (query){
        int x;
        cin >> x;
        int y;
        cin >> y;
        
        cout << m[x][y] << endl;
        query--;
    }
    
    return 0;
}