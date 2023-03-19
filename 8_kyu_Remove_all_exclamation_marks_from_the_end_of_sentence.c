/*
Remove all exclamation marks from the end of sentence.
Examples

remove("Hi!") === "Hi"
remove("Hi!!!") === "Hi"
remove("!Hi") === "!Hi"
remove("!Hi!") === "!Hi"
remove("Hi! Hi!") === "Hi! Hi"
remove("Hi") === "Hi"
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *remove_marks (const char *str_in, char *str_out);

int main(void) {
    char* str = "!!!H!!!!!!";
    char* str_out = malloc(sizeof(str));
    printf("%s", remove_marks(str, str_out));
}

char *remove_marks (const char *str_in, char *str_out) {
    strcpy(str_out, str_in);

    int len = strlen(str_out);
    if (len == 0) {
        str_out[0] = '\0';
    } else {
        int i = len - 1;
        while (i >= 0 && str_out[i] == '!') {
            --i;
        }
        str_out[i + 1] = '\0';
    }

    return str_out; // return it
}