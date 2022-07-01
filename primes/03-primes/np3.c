#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int primeCount = 1;
    int startValue = 3;
    if (argc < 2) {
        printf("You didn't provide any arguments!\n");
        return 1;
    }
    int endValue = atoi(argv[1]);
    printf("Searching for %d primes...\n", endValue);
    if (endValue < 2) {
        printf("You need to enter a number greater than 1!\n");
        return 1;
    }
    int *primes = malloc(sizeof(int) * endValue);
    primes[0] = 2;
    while (primeCount < endValue) {
        int isPrime = 1;
        int squareRoot = (int) sqrt(startValue);
        for (int i = 0; i < primeCount; i++) {
            if (primes[i] > squareRoot) {
                break;
            }
            if (startValue % primes[i] == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            primes[primeCount] = startValue;
            primeCount++;
        }
        startValue += 2;
    }
    printf("The %dth prime is %d\n", endValue, primes[endValue - 1]);
    free(primes);
    return 0;
}