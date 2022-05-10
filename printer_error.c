#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* printerError(char* s);

int main() {
    char* s = "aaaxbbbbyyhwawiwjjjwwm";

    printerError(s);

    return 0;
}

char* printerError(char *s) {
    int e = 0;
    int len = strlen(s);
    char* error = malloc(sizeof(e) * len);

    while(*s) {
        if (*s < 'a' || *s > 'm') {
            e++;
        } s++;
    }

    sprintf(error, "%d/%d", e, len);

    return error;
}