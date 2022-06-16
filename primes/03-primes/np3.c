#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int primeCount = 0;
    int startValue = 2;
    if (argc < 2) {
        printf("You didn't provide any arguments!\n");
        return 1;
    }
    int endValue = atoi(argv[1]);
    if (endValue < 2) {
        printf("You need to enter a number greater than 1!\n");
        return 1;
    }
    // We only need to check primes, because other numbers are multiples of prime numbers.
    int primes[endValue];
    while (primeCount < endValue) {
        if (startValue % 2 == 0 && startValue != 2) {
            startValue++;
            continue;
        }
        int isPrime = 1;
        int maxDivisor = (int) sqrt(startValue) + 1;
        for (int i = 0; i < primeCount; i++) {
            if (primes[i] > maxDivisor) {
                break;
            }
            if (startValue % primes[i] == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            primeCount++;
            primes[primeCount - 1] = startValue;
        }
        startValue += 1;
    }
    printf("%d\n", startValue - 1);
    return 0;
}