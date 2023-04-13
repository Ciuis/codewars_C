//It's pretty straightforward. Your goal is to create a function that removes the first and last characters of a string. You're given one parameter, the original string. You don't have to worry with strings with less than two characters.

#include <string.h>

char* remove_char(char* dst, const char* src) {
    strncpy(dst, src+1, strlen(src) - 2); //return strcpy(d, s+1)[strlen(s)-2] = 0, d;
    return dst;
}