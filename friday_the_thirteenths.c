#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

enum days {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
#define LEN(str) (sizeof(str) - 1)

char *friday_the_thirteenths (int start_year, int end_year) {
// there cant be more than three Friday the 13th a year, interesting is it not ?
    char *fridays = malloc(3 * (end_year - start_year + 1) * LEN("01/13/1970 ") + 1);
    char *ptr = fridays;

    struct tm date = {.tm_mday = 13};

    for (int year = start_year; year <= end_year; year++) {
        date.tm_year = year - 1900;

        for (int month = 0; month < 12; month++) {
            date.tm_mon = month;
            mktime(&date);

            if (date.tm_wday == FRIDAY) // cannot use strftime(), it would add leading zeroes to days/months
                ptr += sprintf(ptr, "%d/13/%d ", date.tm_mon + 1, year);
        }
    }
    ptr[(ptr == fridays) ? 0 : -1] = '\0'; // trailing space

    return realloc(fridays, ptr - fridays + 1);
}

// second variant

/* #include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdio.h>

  return a heap-allocated string, it will be freed
  you can assume that 1970 <= start_year <= end_year
*/

/*
char *friday_the_thirteenths (int start_year, int end_year)
{
    char *res, *p;
    size_t n = (size_t)(end_year - start_year + 1) * 12 * 12;

    if (!(p = res = malloc(n))) return 0;

    for (int y = start_year; y <= end_year; ++y) {

        for (int m = 0; m <= 11; ++m) {
            struct tm time_str = { .tm_year  = y - 1900, .tm_mon   = m, .tm_mday  = 13 };
            if (mktime(&time_str) == (time_t)-1) continue;
            if (time_str.tm_wday != 5) continue;
            p += snprintf(p, 12, "%i/13/%i ", m + 1, y);
        }
    }

    if (p != res) --p;
    *p = 0;
    return res;
}*/
