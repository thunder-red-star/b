#include <stdio.h>
#include <stdlib.h>

// This is an implementation of the Sieve of Eratosthenes. Hopefully it is faster than the naive implementation.
// It is based on the following observation:
// If we know the first few primes, we can easily determine the rest.


int sieve(int n) {
    int *primes = malloc(sizeof(int) * n);
    long i, j, k;
    for (i = 0; i < n; i++) {
        primes[i] = 1;
    }
    primes[0] = 0;
    primes[1] = 0;
    for (i = 2; i < n; i++) {
        if (primes[i]) {
            for (j = i * i; j < n; j += i) {
                primes[j] = 0;
            }
        }
    }
    for (i = 0, k = 0; i < n; i++) {
        if (primes[i]) {
            k++;
        }
    }
    free(primes);
    return k;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("You didn't provide any arguments!\n");
        return 1;
    }
    int endValue = atoi(argv[1]);
    if (endValue < 2) {
        printf("You need to enter a number greater than 1!\n");
        return 1;
    }
    printf("Searching for the %dth prime...\n", endValue);
    int primes = sieve(endValue);
    printf("There are %d primes below %d.\n", primes, endValue);
    return 0;
}