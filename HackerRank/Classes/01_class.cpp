#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <sstream>

class   Student{
    private:
        int     age;
        string  first_name;
        string  last_name;
        int     standard;
    public:
        void    set_age(const int& age) { this->age = age; }
        int     get_age() { return age; }
        void    set_first_name(const string &name) { first_name = name; }
        string  get_first_name() { return first_name; }
        void    set_last_name(const string &name) { last_name = name; }
        string  get_last_name() { return last_name; }
        void    set_standard(const int &standard) { this->standard = standard; }
        int     get_standard() { return standard; }
        string  to_string(){
            stringstream    ss;
            ss << age << "," << first_name << "," << last_name << "," << standard;
            
            return ss.str();
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    Student obj;
    string  str;
    int     n;
    
    cin >> n;
    obj.set_age(n);
    cin >> str;
    obj.set_first_name(str);
    cin >> str;
    obj.set_last_name(str);
    cin >> n;
    obj.set_standard(n);
    
    cout << obj.get_age() << endl;
    cout << obj.get_last_name() << ", " << obj.get_first_name() << endl;
    cout << obj.get_standard() << endl;
    cout << endl;
    cout << obj.to_string() << endl;
      
    return 0;
}