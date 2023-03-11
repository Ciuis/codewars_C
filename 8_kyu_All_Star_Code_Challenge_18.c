/*Create a function that accepts a string and a single character, and returns an integer of the count of occurrences the 2nd argument is found in the first one.

If no occurrences can be found, a count of 0 should be returned.

("Hello", "o")  ==>  1
("Hello", "l")  ==>  2
("", "z")       ==>  0

str_count("Hello", 'o'); // returns 1
str_count("Hello", 'l'); // returns 2
str_count("", 'z'); // returns 0

Notes

        The first argument can be an empty string
        In languages with no distinct character data type, the second argument will be a string of length 1*/
#include <stddef.h>
#include <stdio.h>

size_t str_count(const char *str, char letter);

int main(void) {
    char* str = "Hellol";
    printf("%d", str_count(str, 'o'));
}

size_t str_count(const char *str, char letter) {
    int cnt = 0;
    do {
        if(*str == letter) ++cnt;
    } while(*str++ != '\0');
    return cnt;
}