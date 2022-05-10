#include <stdio.h>

int get_sum(int a, int b);

int main() {
    int a = 5;
    int b = 8;

    printf("%d\n", get_sum(a, b));
}

int get_sum(int a, int b) {
    int sum = 0;
    if (a > b) {
        for (int i = a; i >= b; --i) {
            sum += i;
        }
        return sum;
    } else if (a < b) {
        for (int j = a; j <= b; ++j) {
             sum += j;
        }
        return sum;
    } else {
        return a;
    }
}
