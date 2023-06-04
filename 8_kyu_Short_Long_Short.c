/*
Given 2 strings, a and b, return a string of the form short+long+short, with the shorter string on the outside and the longer string on the inside. The strings will not be the same length, but they may be empty ( zero length ).

Hint for R users:

The length of string is not always the same as the number of characters

For example: (Input1, Input2) --> output

("1", "22") --> "1221"
("22", "1") --> "1221"
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *short_long_short (const char *a, const char *b) {
    char* c = {0};
    if (strlen(a) == 0) {
        c = calloc(strlen(b) + 1, sizeof(char));
        sprintf(c, "%s",b);
    } else if (strlen(b) == 0) {
        c = calloc(strlen(a) + 1, sizeof(char));
        sprintf(c, "%s",a);
    } else if (strlen(a) < strlen(b)) {
        c = calloc(strlen(a) + strlen(b) + strlen(a) + 1, sizeof(char));
        sprintf(c, "%s%s%s", a, b, a);
    } else if (strlen(b) < strlen(a)) {
        c = calloc(strlen(b) + strlen(a) + strlen(b) + 1, sizeof(char));
        sprintf(c, "%s%s%s", b, a, b);
    }

    return c;
}