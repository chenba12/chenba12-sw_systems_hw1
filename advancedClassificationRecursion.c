#include "NumClass.h"

int reverse(int x);

int power(int a, int b);

int isPalindrome(int x) {
    if (x == reverse(x)) {
        return 1;
    }
    return 0;
}


int reverse(int x) {
    int digit = x % 10;
    if (x == 0)
        return 0;
    return (int) ((x % 10 * power(10, digit)) + reverse(x / 10));
}

int power(int a, int b) {
    int sum = 1;
    for (int i = 1; i <= b; ++i) {
        sum *= a;
    }
    return sum;
}


int countDigits(int x) {
    int counter = 0;
    while (x > 0) {
        counter++;
        x = x / 10;
    }
    return counter;
}

int isArmStrongRec(int x, int digits) {
    if (x == 0) {
        return 0;
    }
    return (power(x % 10, digits) + isArmStrongRec(x / 10, digits));
}

int isArmStrong(int x) {
    int digits = countDigits(x);
    if (x == isArmStrongRec(x, digits)) {
        return 1;
    } else {
        return 0;
    }
}