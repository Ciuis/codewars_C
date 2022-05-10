#include <stdio.h>

int find_even_index(const int *values, int length);

int main() {
    int values[] = {1,100,50,-51,1,1};
    int length = sizeof(values) / sizeof(values[0]);

    printf("%d", find_even_index(values, length));

    //printf("%d", length);

    return  0;
}

int find_even_index(const int *values, int length) {
    int sum_1 = 0,
        sum_2 = 0;
    for (int i = 0; i < length; ++i) {
        sum_1 += values[i];
    }
    for (int k = 0; k < length; ++k) {
        if ((sum_1 - values[k]) == sum_2) {
            return k;
        }
        printf("%d: %d\n", k, sum_1);
        printf("%d: %d\n", k, sum_2);
        sum_2 += values[k];
        sum_1 -= values[k];
    }

    return -1;
}

