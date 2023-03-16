/*Remove all exclamation marks from sentence but ensure a exclamation mark at the end of string. For a beginner kata, you can assume that the input data is always a non empty string, no need to verify it.
Examples

remove("Hi!") === "Hi!"
remove("Hi!!!") === "Hi!"
remove("!Hi") === "Hi!"
remove("!Hi!") === "Hi!"
remove("Hi! Hi!") === "Hi Hi!"
remove("Hi") === "Hi!"*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *remove_bang (const char *string);

int main(void) {
    char* s = "!Hi";

    printf("%s", remove_bang(s));
}

char *remove_bang (const char *string) {
    char *r = calloc(strlen(string) + 1, 1);
    int n = 0;
    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] != '!') {
            r[n] = string[i];
            n++;
        }
    }
    r[n] = '!';

    return r;
}