#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int digPow(int n, int p);

int main() {
    int n = 46288;
    int p = 3;
    digPow(n, p);

}

int digPow(int n, int p) {
    int m = n;
    int t = p;
    unsigned int len = (int)(log10((float)n)) + 1;
    char* arr = (char*)malloc(len * sizeof(char));
    char* target = (char*)malloc(len * sizeof(char));
    while(m > 0) {
        for (int i = 0; i < len; ++i) {
            arr[i] = m % 10;
            m /= 10;
        }
    }

    for (int i = len; i >= 0; i--) {
        target[len - i] = arr[i - 1];
    }

    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += pow(target[i], t);
        t++;
    }

    if ((sum % n) == 0) {
        return sum / n;
    }

    return -1;

    for (int i = 0; i < len; ++i) {
        printf("%d", target[i]);
    }

    printf("\n");

    printf("%d %d %d %d", sum, n, p, sum / n);


}