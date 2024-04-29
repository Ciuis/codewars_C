/*
No Story

No Description

Only by Thinking and Testing

        Look at result of testcase, guess the code!*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* testit(const char *s);

int main(void) {
    char* string = "abc";

    printf("%s", testit(string));
    return 0;
}

char* testit(const char *s) {
    char* tmp = malloc(strlen(s) + 1);
    int i;

    for (i = 0; i + 1 < strlen(s); i += 2) {
        char s1 = s[i];
        char s2 = s[i+1];
        sprintf(tmp, "%c", (s1 + s2) / 2);
    }

    return tmp;
}