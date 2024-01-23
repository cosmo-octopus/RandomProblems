#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class   BadLengthException{
    private:
        int n;
    public:
        BadLengthException(const int &err){
            n = err;
        }
        
        int what(){
            return n;
        }
};

bool    checkUsername(string username){
    bool    valid = 1;
    int     len = username.length();
    
    if (len < 5){
        throw BadLengthException(len);
    }
    for (int i = 0; i < len - 1; i++){
        if (username[i] == 'w' && username[i + 1] == 'w')
            valid = 0;
    }
    
    return valid;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    
    while (n--){
        string  username;
        cin >> username;
        
        try {
            bool    valid = checkUsername(username);
            if (valid)
                cout << "Valid" << endl;
            else
                cout << "Invalid" << endl;
        }
        catch (BadLengthException e){
            cout << "Too short: " << e.what() << endl;        
        }
    }
    
    return 0;
}