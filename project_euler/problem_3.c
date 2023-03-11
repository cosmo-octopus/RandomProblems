/*
Problem 3
Largest prime factor

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include <stdio.h>

long long next_prime_number(long long primeNum);

long long ft_largest_prime_factor(long long Num) {
    long long largestPrime = -1;
    
    for (long long i = 2; i <= Num; i = next_prime_number(i)) {
        if (Num % i == 0) {
            largestPrime = i;
            Num = Num / i;
        }
    }
    return largestPrime;
}

long long next_prime_number(long long primeNum) {
    primeNum++;
    int counter = 0;
    for (long long i = 2; i < primeNum; i++) {
        if (primeNum % i == 0) {
            counter++;
        }
    }
    if (counter > 0) {
        return next_prime_number(primeNum);
    } else {
        return primeNum;
    }
}

int main() {
    long long number = 600851475143;
    printf("%lld\n", ft_largest_prime_factor(number));
    return 0;
}