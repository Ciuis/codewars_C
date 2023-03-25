/*
Write a function that accepts an integer n and a string s as parameters, and returns a string of s repeated exactly n times.
Examples (input -> output)

6, "I"     -> "IIIIII"
5, "Hello" -> "HelloHelloHelloHelloHello"

*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *repeat_str(size_t count, const char *src);

int main(void) {
    char* src = "IW";
    size_t count = 4;
    printf("%s", repeat_str(count, src));
}

char *repeat_str(size_t count, const char *src) {
    char* str_out = (char*) calloc(strlen(src) * count + 1, sizeof(char));
    for (int i = 0; i < count; ++i) {
        strcat(str_out, src);
    }
    return str_out;
}

/*
char *repeat_str(size_t count, const char *src) {
    char *rep = calloc(sizeof(char),strlen(src) * count + 1);

    while (count--)
        strcat(rep, src);

    return rep;
}*/
