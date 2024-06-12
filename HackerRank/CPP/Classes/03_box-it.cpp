#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class   Box{
    private:
        int l;
        int b;
        int h;
    public:
        Box(): l(0), b(0), h(0) {}
        Box(const int& l, const int& b, const int& h): l(l), b(b), h(h) {}
        Box(const Box& other);
        int         getLength();
        int         getBreadth();
        int         getHeight();
        long long   CalculateVolume();
        
        friend bool operator<(const Box& lhs, const Box& rhs);
        friend ostream  &operator<<(ostream& os, const Box& box);
};

Box::Box(const Box& other){
    this->l = other.l;
    this->b = other.b;
    this->h = other.h;
}

int     Box::getLength(){
    return l;
}

int     Box::getBreadth(){
    return b;
}

int     Box::getHeight(){
    return h;
}

long long   Box::CalculateVolume(){
    return (long long)l * b * h;
}

bool    operator< (const Box& lhs, const Box& rhs){
    if( (lhs.l < rhs.l) || ((lhs.b < rhs.b) && (lhs.l == rhs.l)) 
        || ((lhs.h < rhs.h) && (lhs.l == rhs.l) && (lhs.b == rhs.b)) )
        return 1;
    return 0;
}

ostream&    operator<<(ostream& os, const Box& box){
    os << box.l << " " << box.b << " " << box.h;
    
    return os;
}

void check2()
{
    int n;
    cin >> n;
    
    Box temp;
    for(int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        
        if (type == 1){
            cout << temp << endl;
        }
        if (type == 2){
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3){
            int l, b, h;
            cin >> l >> b >>h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
                cout << "Lesser\n";
            else
                cout << "Greater\n";
        }
        if (type == 4){
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5){
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main()
{
    check2();
}