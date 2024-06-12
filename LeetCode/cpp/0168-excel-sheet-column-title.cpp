#include <iostream>
#include <string>


std::string convertToTitle(int num) {
    std::string res;

    while (num--) {
        std::string str{static_cast<char>('A' + (num % 26))};
        res = str + res;
        num = num / 26;
    }

    return res;
}

int main() {

    int num1 = 1;
    int num2 = 28;
    int num3 = 701;

    std::cout << "Column title for " << num1 << " is " << convertToTitle(num1) << "\n";
    std::cout << "Column title for " << num2 << " is " << convertToTitle(num2) << "\n";
    std::cout << "Column title for " << num3 << " is " << convertToTitle(num3) << "\n";

    return 0;
}