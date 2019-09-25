#include<bits/stdc++.h>
using namespace std;

int* divisiblePrimes(int, const int*, int*);

int main() {
    const int PRIME_NUMS_BETWEEN_0_AND_100 = 25;
    int primeNumbers[PRIME_NUMS_BETWEEN_0_AND_100]
    = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    int input, number, j, savedInput;
    while (cin >> input && input != 0) {
        savedInput = input;
        int primeNumbersCount[PRIME_NUMS_BETWEEN_0_AND_100] = {0};
        while (input != 1) {
            number = input;
            divisiblePrimes(number, primeNumbers, primeNumbersCount);
            input--;
        }


        for (number = 24; number >= 0; --number) {
            if (primeNumbersCount[number] != 0)
                break;
        }
        j = number;
        printf("%3d! =", savedInput);
        int maxPrimeNumbersToPrint = 0;
        if (j >= 15) maxPrimeNumbersToPrint = 0;
        else maxPrimeNumbersToPrint = 15;
        for (number = 0; number <= j; number++) {
            printf("%3d", primeNumbersCount [number]);
            maxPrimeNumbersToPrint++;
            if (maxPrimeNumbersToPrint == 15)
                printf("\n%6c",' ');
        } printf("\n");
    }

    return 0;
}

int* divisiblePrimes(int number, const int *primeNumbers, int *primeNumbersCount/*, int j*/)
{
    int j = 0;
    while (number > 1) {
        int count = 0;
        while (number % primeNumbers[j] == 0) {
            number /= primeNumbers[j];
            count++;
        }
        primeNumbersCount[j] += count;
        ++j;
    }
    return primeNumbersCount;
}
