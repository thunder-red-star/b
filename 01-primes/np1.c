#include <stdio.h>
c
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
        int isPrime = 1;
        for (int i = 2; i < startValue; i++) {
            if (startValue % i == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            primeCount++;
        }
        startValue++;
    }
    printf("%d\n", startValue - 1);
    return 0;
}