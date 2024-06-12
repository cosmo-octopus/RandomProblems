#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class   Student{
    private:
        vector<int> scores;
    public:
        void    input();
        int     calculateTotalScore();
};

void    Student::input(){
    for (int i = 0; i < 5; i++){
        int n;
        cin >> n;
                
        this->scores.push_back(n);
    }
}

int     Student::calculateTotalScore(){
    int res = 0;
    
    for (int i = 0; i < scores.size(); i++){
        res += scores[i];
    }
    
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    
    vector<Student> vec;
    vec.reserve(n);
    
    for(int i = 0; i < n; i++){
        vec[i].input();
    }
    
    int counter = 0;
    int kristen = vec[0].calculateTotalScore();
    for (int i = 1; i < n; i++){
        if (vec[i].calculateTotalScore() > kristen)
            counter++;
    }
    
    cout << counter << endl;
     
    return 0;
}