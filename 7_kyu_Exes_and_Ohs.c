/*
Check to see if a string has the same amount of 'x's and 'o's. The method must return a boolean and be case insensitive. The string can contain any char.

Examples input/output:

XO("ooxx") => true
XO("xooxx") => false
XO("ooxXm") => true
XO("zpzpzpp") => true // when no 'x' and 'o' is present should return true
XO("zzoo") => false*/

#include <stdbool.h>
#include <ctype.h>

bool xo (const char* str) {
    int x = 0;
    int o = 0;

    while (*str != '\0') {
        char c = tolower(*str);
        switch (c) {
            case 'x': x++; break;
            case 'o': o++; break;
            default:
                break;
        }
        ++str;
    }
    return x == o;
}