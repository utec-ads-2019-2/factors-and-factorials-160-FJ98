#include<bits/stdc++.h>
using namespace std;

const int PRIME_NUMS_BETWEEN_0_AND_100 = 25;

int* countDivisiblePrimesFrequency(int, int*);
void printAccordingToUVAFormat(int, int*);

int main() {
    int input, savedInput;
    while (cin >> input && input != 0) {
        savedInput = input;
        int primeNumbersCount[PRIME_NUMS_BETWEEN_0_AND_100] = {0};
        while (input != 1) {
            countDivisiblePrimesFrequency(input, primeNumbersCount);
            --input;
        }
        printAccordingToUVAFormat(savedInput, primeNumbersCount);
    }

    return 0;
}


int* countDivisiblePrimesFrequency(int number, int *primeNumbersCount)
{
    int primeNumbers[PRIME_NUMS_BETWEEN_0_AND_100]
            = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
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


void printAccordingToUVAFormat(int savedInput, int* primeNumbersCount)
{
    int numbersToPrint = 0;

    for (numbersToPrint = PRIME_NUMS_BETWEEN_0_AND_100 - 1; numbersToPrint >= 0; --numbersToPrint)
        if (primeNumbersCount[numbersToPrint] != 0)
            break;

    int printFormatLimit = 15;
    printFormatLimit = (numbersToPrint >= printFormatLimit) ? 0 : 15;

    printf("%3d! =", savedInput);
    for (int j = 0; j <= numbersToPrint; ++j)
    {
        printf("%3d", primeNumbersCount [j]);
        printFormatLimit++;
        if (printFormatLimit == 15)
            printf("\n%6c",' ');
    }
    printf("\n");
}
