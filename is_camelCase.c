#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h> // NULL

char* solution(const char *camelCase);

int main() {
    char* s = "thisIsAVeryLongIdentifierName";

    solution(s);
}

//returned buffer should be dynamically allocated and will be freed by a caller
char* solution(const char *camelCase) {
    int count = 0;
    char* newStr;

    for (int i = 0; camelCase[i] != '\0'; ++i) {
        printf("%s", camelCase);
    }

    return NULL;
}



/*
while (*camelCase) {
if (*camelCase >= 'A' && *camelCase <= 'Z') {
count++;
}

newStr = malloc(strlen(camelCase) + count);
camelCase++;
*newStr = *camelCase;
}*/
