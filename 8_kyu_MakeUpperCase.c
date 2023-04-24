// Write a function which converts the input string to uppercase.

#include <ctype.h>

char *makeUpperCase (char *string) {
    for (int i = 0; string[i] != '\0'; ++i) string[i] = toupper(string[i]);

    return string;
}