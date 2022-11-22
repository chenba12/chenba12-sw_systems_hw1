#include "NumClass.h"

long factorial(long x) {
    long fact = 1;
    for (int i = 1; i <= x; i++) {
        fact = fact * i;
    }
    return fact;
}


int isStrong(int x) {
    int original = x;
    long sum = 0;
    while (x > 0) {
        sum += factorial((long) (x % 10));
        x = x / 10;
    }
    return sum == original;
}


int isPrime(int x) {
    if (x == 1 || x == 2) return 1;
    if (x % 2 == 0) return 0;
    for (int i = 2; i < x / 2; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
