#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mxdiflg(
        const char *const arr_1[], size_t len_1,
        const char *const arr_2[], size_t len_2
);

int main() {
    char *a1[] = {"hoqq", "bbllkw", "oox", "ejjuyyy", "plmiis", "xxxzgpsssa", "xxwwkktt", "znnnnfqknaz", "qqquuhii", "dvvvwz"};
    size_t len_1 = sizeof(a1) / sizeof(a1[0]);
    char *a2[] = {"cccooommaaqqoxii", "gggqaffhhh", "tttoowwwmmww"};
    size_t len_2 = sizeof(a2) / sizeof(a2[0]);

    mxdiflg(a1, len_1, a2, len_2);
}

int mxdiflg(
        const char *const arr_1[], size_t len_1,
        const char *const arr_2[], size_t len_2) {
    int max = 0;

    if (len_1 * len_2 == 0) {
        return -1;
    }

    for (int i = 0; i < len_1; i++) {
        for (int k = 0; k < len_2; k++) {
            int diff = abs(strlen(arr_1[i]) - strlen(arr_2[k]));

            if(diff > max) {
                max = diff;
            }
        }
    }

    printf("%d", max);
}