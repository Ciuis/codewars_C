#include <stddef.h>
#include <stdio.h>
#include <string.h>

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
    int diffA = 0,
        diffB = 0,
        max1 = 0,
        max2 = 0,
        min1 = 9999,
        min2 = 9999;

    if (len_1 * len_2 == 0) {
        return -1;
    }

    for(int i = 0; i < len_1; ++i) {
        int len = strlen(arr_1[i]);

        len > max1 ? max1 = len : max1;
        len < min1 ? min1 = len : min1;
    }
    diffA = max1 - min1;

    for (int k = 0; k < len_2; ++k) {
        int len2 = strlen(arr_2[k]);

        len2 > max2 ? max2 = len2 : max2;
        len2 < min2 ? min2 = len2 : min2;
    }
    diffB = max2 - min2;

    printf("%d %d\n", diffA, diffB);

    return diffA > diffB ? diffA : diffB;

}