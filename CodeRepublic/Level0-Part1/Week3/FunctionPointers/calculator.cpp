/* PROBLEM: Implement a calculator program
that uses std::map and function pointers.
The function pointers are linked to corresponding
numerical operations performed by the function of
the calculator. */

#include <iostream>
#include <map>
#include <string>

int add(int a, int b)
{
    return (a + b);
}

int subtract(int a, int b)
{
    return (a - b);
}

int multiply(int a, int b)
{
    return (a * b);
}

int divide(int a, int b)
{
    if (b != 0)
        return (a / b);
	else 
	{
        std::cerr << "Error: Division by zero" << std::endl;
        return 0;
    }
}

int modulus(int a, int b)
{
    if (b != 0)
        return (a % b);
	else 
	{
        std::cerr << "Error: Modulus by zero" << std::endl;
        return (0);
    }
}

int main() {
    int num1, num2;
    std::string oper;

    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the operator: ";
    std::cin >> oper;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // maps keys (strings) to function pointers
    std::map<std::string, int(*)(int, int)> functionMap;
    
    // add functions to the map
    functionMap["+"] = add;
    functionMap["-"] = subtract;
    functionMap["*"] = multiply;
    functionMap["/"] = divide;
    functionMap["%"] = modulus;

    if (functionMap.find(oper) != functionMap.end())
	{
        int result = functionMap[oper](num1, num2);
        std::cout << "Result: " << result << std::endl;
    }
	else
        std::cerr << "Error: Operator not recognized" << std::endl;
}