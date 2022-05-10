#include <stdlib.h>
#include <stdio.h>

char *longest (const char *s1, const char *s2);

int main() {
    char* a = "mmmmmmmmmhhhhhhhhhnnnmmmmmqxxxxxxxjjjccccccccc";
    char* b = "hhhhhhhhhhvvvvvvvvvppppppppphhhoouuuuuuuummqqq";

    printf("%s", longest(a, b));
}

char* longest(const char* s1, const char* s2) {
    char letters [26] = {0}, *temp, *final = temp = (char *) calloc(sizeof(char), 26);;
    while(*s1) letters[*(s1++) - 'a']++;
    while(*s2) letters[*(s2++) - 'a']++;

    for(int i = 0; i < 26; i++)
        if(letters[i])
            *(temp++) = 'a' + i;

    return final;
}