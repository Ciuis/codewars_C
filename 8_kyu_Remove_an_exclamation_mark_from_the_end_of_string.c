/*
Remove an exclamation mark from the end of a string. For a beginner kata, you can assume that the input data is always a string, no need to verify it.
Examples

remove("Hi!") == "Hi"
remove("Hi!!!") == "Hi!!"
remove("!Hi") == "!Hi"
remove("!Hi!") == "!Hi"
remove("Hi! Hi!") == "Hi! Hi"
remove("Hi") == "Hi"
*/

#include <string.h>

char *remove_exclamation_mark(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '!') {
        str[len - 1] = '\0';
    }
    return str;
}