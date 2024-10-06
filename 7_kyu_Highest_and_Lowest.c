/*
In this little assignment you are given a string of space separated numbers, and have to return the highest and lowest number.

Examples
high_and_low("1 2 3 4 5") // return "5 1"
high_and_low("1 2 -3 4 5") // return "5 -3"
high_and_low("1 9 3 4 -5") // return "9 -5"
high_and_low("1 2 3 4 5", result) // result "5 1"
high_and_low("1 2 -3 4 5", result) // result "5 -3"
high_and_low("1 9 3 4 -5", result) // result "9 -5"
Notes
        All numbers are valid Int32, no need to validate them.
There will always be at least one number in the input string.
Output string must be two numbers separated by a single space, and highest number is first.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void high_and_low (const char *strnum, char *result) {
    int min = INT_MAX;
    int max = INT_MIN;
    char* endptr = (char*) strnum;

    while (*strnum) {
        int tmp = strtol(strnum, &endptr, 10);
        if (tmp < min) min = tmp;
        if (tmp > max) max = tmp;
        strnum = endptr;
        while (*strnum == ' ') strnum++;
    }

    sprintf(result, "%d %d", max, min);
}