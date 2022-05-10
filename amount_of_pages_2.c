/**
 * Counts number by count of digits
 */

#include <stdio.h>
#include <math.h>

unsigned amount_of_pages(unsigned summary);

int main() {
    unsigned summary = 60372;

    printf("Summary: %d\n", summary);
    printf("Pages: %d\n", amount_of_pages(summary));
}

unsigned amount_of_pages(unsigned summary) {
    unsigned pages = 0;
    unsigned len = 0;

    for (int i = summary; i > 1; i /= 10) {
        len++;
    }

    //printf("%d\n", len);

    if (len == 1 || summary == 0) return summary;

    for (int i = 1; i  < len; ++i) {
        summary += (pow(10, i) - 1);
        printf("%d\t", summary / len);
    }


    return (pages + summary) / len;
}

/*
   N + (N-9) + (N - 99) + (N - 999) + (N - 9999) + (N - 99999) = 269294
        6N = 269294 + 9 + 99 + 999 + 9999 + 99999
                6N = 1203
                        N = 401
*/
