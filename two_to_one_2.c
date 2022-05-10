#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longest (const char *s1, const char *s2);

int main() {
    char* a = "mmmmmmmmmhhhhhhhhhnnnmmmmmqxxxxxxxjjjccccccccc";
    char* b = "hhhhhhhhhhvvvvvvvvvppppppppphhhoouuuuuuuummqqq";

    printf("%s", longest(a, b));



}

char *longest (const char *s1, const char *s2) {
    char* s3 = malloc(strlen(s1) + strlen(s2));

    if(!s3) {
        printf("memory allocation failed!\n");
        return NULL;
    }

    /**
     * concat
     */
    memcpy(s3, s1, strlen(s1));
    memcpy(s3 + strlen(s1), s2, strlen(s2) + 1);



    char tmp;
    for (int k = 0; k < strlen(s3); ++k) {
        for (int l = k + 1; l < strlen(s3); ++l) {
            if (s3[k] > s3[l]) {
                tmp = s3[k];
                s3[k] = s3[l];
                s3[l] = tmp;
            }
        }
    }

    int i = 0;

    while(s3[i + 1] != '\0') {
        if (s3[i] == s3[i + 1]) {
            for (int j = 0; (j < strlen(s3)); ++j) {
                s3[i + j + 1] = s3[i + j + 2];
            }
        } else {
            i++;
        }
    }

    return s3;
}