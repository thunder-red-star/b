#include <stdio.h>

// Find the millionth prime number without any optimizations.

int main() {
    int primeCount = 0;
    int startValue = 2;
    while (primeCount < 1000000) {
        int isPrime = 1;
        for (int i = 2; i < startValue; i++) {
            if (startValue % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            primeCount++;
            printf("Found prime %d, count is %d\n", startValue, primeCount);
        }
        startValue++;
    }
    printf("%d\n", startValue - 1);
    return 0;
}