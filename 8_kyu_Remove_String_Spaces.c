/*Write a function that removes the spaces from the string, then return the resultant string.

Examples:

Input -> Output
"8 j 8   mBliB8g  imjB8B8  jl  B" -> "8j8mBliB8gimjB8B8jlB"
"8 8 Bi fk8h B 8 BB8B B B  B888 c hl8 BhB fd" -> "88Bifk8hB8BB8BBBB888chl8BhBfd"
"8aaaaa dddd r     " -> "8aaaaaddddr"

For C and Nasm, you must return a new dynamically allocated string.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *no_space(const char *str_in);

int main(void) {
    char* str_in = "8 8 Bi fk8h B 8 BB8B B B  B888 c hl8 BhB fd";
    printf("%s", no_space(str_in));
}

char *no_space(const char *str_in) {
    char* str_out = (char*)malloc(strlen(str_in) + 1);

    int j = 0;
    for (int i = 0; str_in[i] != '\0'; ++i) {
        if (str_in[i] != ' ') {
            str_out[j] = str_in[i];
            ++j;
        }
    }
    str_out[j] = '\0';

    return str_out;
}

/*char *no_space(char *s) {
    char *res = strdup(s), *q = res;
    for (; *s; s++) if (*s != ' ') *q++ = *s;
    return *q = 0, res;
}*/

/*
char *no_space(const char *str) {
    char* const ret = calloc(strlen(str)+1, sizeof(char));
    for (char* out = ret; *str!=0; str++) if (*str != ' ') *out++ = *str;
    return ret;
}*/
