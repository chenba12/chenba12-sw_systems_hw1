
int power(int a, int b);

int isArmStrong(int x) {
    int original = x;
    int counter = 0;
    int sum = 0;
    while (x != 0) {
        counter++;
        x = x / 10;
    }
    x = original;
    while (x != 0) {
        sum += power(x % 10, counter);
        x = x / 10;
    }

    return original == sum;
}


int isPalindrome(int x) {
    int original = x;
    int reverse = 0;
    int temp;
    while (x != 0) {
        temp = x % 10;
        reverse = reverse * 10 + temp;
        x = x / 10;
    }
    return original == reverse;
}

int power(int a, int b) {
    int sum = 1;
    for (int i = 1; i <= b; ++i) {
        sum *= a;
    }
    return sum;
}
