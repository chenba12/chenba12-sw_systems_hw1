#include "NumClass.h"

int reverse(int num1, int num2);

int countDigits(int x);

int power(int a, int b);

int isPalindrome(int x) {
    if (x == reverse(x, 0)) {
        return 1;
    }
    return 0;
}


int reverse(int x, int y) {
    if (x == 0) {
        return y;
    }
    y = y * 10;
    y += (x % 10);
    x = x / 10;
    return reverse(x, y);
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
