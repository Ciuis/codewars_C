#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t duplicate_count(const char *text);

int main() {
    char* text = "indivisibility";
    duplicate_count(text);
}

size_t duplicate_count(const char *text) {
    size_t count = 0;
    int p = 0;
    char pArr[256];

    for (int i = 0; text[i] != '\0'; ++i) {
        for (int j = i + 1; text[j] != '\0'; ++j) {
            if (text[i] == text[j]) {
                pArr[p] = text[i];
                p++;
                printf("%d %c\n", p, pArr[p]);
                break;
            }
        }
    }
    printf("%d", p);
}