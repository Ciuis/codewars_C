/**
 * Counts number of digits in number row
 */

#include <stdio.h>
#include <stdlib.h>

unsigned amount_of_pages(unsigned summary);

int main() {
    int summary = 60372;

    printf("%d", amount_of_pages(summary));
}

unsigned amount_of_pages(unsigned summary) {
    int pages = 0;
    for (int i = 1; i <= summary; i *= 10) {
        printf("%d\n", pages);
        pages += (summary - i + 1);
    }
/*    for (int i = summary; i >= 1; i /= 10) {*/


    return pages;
}