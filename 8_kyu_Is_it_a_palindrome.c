// Write a function that checks if a given string (case insensitive) is a palindrome.

#include <stdbool.h>
#include <string.h>
#include <ctype.h>


bool is_palindrome(const char *str_in) {
    for (int i = 0; i < strlen(str_in); ++i) {
        if (strlen(str_in) % 2 != 0 && i == strlen(str_in) - i - 1) return true;
        if (tolower(str_in[i]) != tolower(str_in[strlen(str_in)-i-1])) return false;
    }
    return true;
}