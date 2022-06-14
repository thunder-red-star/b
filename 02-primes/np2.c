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
    while (primeCount < endValue) {
        if (startValue % 2 == 0) {
            startValue++;
            continue;
        }
        int isPrime = 1;
        int maxDivisor = (int) sqrt(startValue);
        for (int i = 3; i < maxDivisor; i += 2) {
            if (startValue % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            primeCount++;
        }
        startValue += 1;
    }
    printf("%d\n", startValue - 1);
    return 0;
}