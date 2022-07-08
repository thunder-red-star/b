#include <stdio.h>
#include <stdlib.h>
#include "bitarray.h"
// This is an implementation of the Sieve of Eratosthenes. Hopefully it is faster than the naive implementation.
// It is based on the following observation:
// If we know the first few primes, we can easily determine the rest.

// Our new implementation will store values starting with 0, 1, 2, and then all odd numbers.
// Therefore, we will not have to allocate nearly as much memory as the bitarray that stores all numbers from 0 to n.
// We will only need to allocate memory for the bitarray that stores all odd numbers.
// The numbers our bitarray will store this time will look like this:
// 0, 1, 2, 3, 5, 7, 9, 11, ...

int sieve(int n) {
    unsigned int* bits = calloc(sizeof(unsigned int), (((n >> 1) - 1) >> 5) + 1);
    register long int i, j, k;
    k = 1;
    for (i = 3; i < n; i += 2) {
        if ((bits[((i >> 1) - 1) >> 5] & (1 << (((i >> 1) - 1) % 32))) != 0) continue;
        for (j = i * i; j < n; j += i << 1) {
            bits[((j >> 1) - 1) >> 5] |= (1 << (((j >> 1) - 1) % 32));
        }
        k++;
    }
    free(bits);
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