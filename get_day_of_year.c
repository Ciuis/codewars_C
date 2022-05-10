#include <stdio.h>

int get_day_of_year (const int date[3]);

int main() {
    int date[3] = {29, 2, 2000};
    printf("%d", get_day_of_year(date));
}

int get_day_of_year (const int date[3]) {
    int isLeap = 0;
    if (date[2] % 4 == 0 && (date[2] % 100 != 0 || date[2] % 400 == 0)) {
        isLeap = 1;
    }
    static int dBefore[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

    int sum = 0;
    date[1] > 2 ? (sum = date[0] + dBefore[date[1] - 1] + isLeap) : (sum = date[0] + dBefore[date[1] - 1]);

    printf("%d %d\n", isLeap, date[2]);
    return sum;
}