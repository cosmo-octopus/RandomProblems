#include <iostream>

union Currency
{
    double from;
    double to;
};

// Function to convert the currency based on the exchange rate
void convertCurrency(Currency& amount, char from, char to, double rate)
{
    if ((from == 'D' && to == 'E') || (from == 'E' && to == 'D'))
        amount.to = amount.from * rate;
    else
	    std::cout << "Invalid conversion." << std::endl;
}

int main() {
    Currency amount;

    char fromCurrency, toCurrency;
    double exchangeRate;

	std::cout << "Enter the currency (D for dollars, E for euros): ";
	std::cin >> fromCurrency;

    std::cout << "Enter the amount: ";
    std::cin >> amount.from;

    std::cout << "Enter the exchange rate (D to E): ";
    std::cin >> exchangeRate;

    std::cout << "Enter the target currency (D for dollars, E for euros): ";
    std::cin >> toCurrency;

    convertCurrency(amount, fromCurrency, toCurrency, exchangeRate);

    if (toCurrency == 'D')
        std::cout << "Converted amount in dollars: " << amount.from << std::endl;
    else if (toCurrency == 'E')
        std::cout << "Converted amount in euros: " << amount.to << std::endl;
}