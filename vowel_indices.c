/*We want to know the index of the vowels in a given word, for example, there are two vowels in the word super (the second and fourth letters).

So given a string "super", we should return a list of [2, 4].

Some examples:
Mmmm  => []
Super => [2,4]
Apple => [1,5]
YoMama -> [1,2,4,6]

NOTES

        Vowels in this context refers to: a e i o u y (including upper case)
This is indexed from [1..n] (not zero indexed!)*/

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define vowels "a, e, i, o, u, y"

int *vowel_indices (const char *string, size_t *nb_vowels);

int main() {
    const char *string = "apple";
    size_t *nb_vowels = malloc(strlen(string) * sizeof(char) + 1);
    nb_vowels = vowel_indices(string, nb_vowels);
    for (int i = 0; i < strlen(string); ++i) {
        printf("%d ", nb_vowels[i]);
    }

}


int *vowel_indices (const char *string, size_t *nb_vowels)
{
    *nb_vowels = 0;

    for (const char *ptr = string; *ptr; ptr++)
        *nb_vowels += !!strchr("aeiouy", tolower(*ptr));

    int *indices = malloc(*nb_vowels * sizeof *indices);

    for (size_t i = 0, j = 0; string[i] != '\0'; i++)
        if (strchr("aeiouy", tolower(string[i])))
            indices[j++] = i + 1;

    return indices;
}

//VAR.2

/*
int *vowel_indices (const char *string, size_t *nb_vowels)
{
    int *ret = malloc(strlen(string) * sizeof(int));

    *nb_vowels = 0;

    for (const char *s = string; *s; s++)
        if (strchr("AEIOUYaeiouy", *s))
            ret[(*nb_vowels)++] = s - string + 1;

    return realloc (ret, *nb_vowels * sizeof(int));
}*/


int* indices (const char* string, size_t* nums) {
    int n = 0;
    *nums = 0;
    int* indices = malloc(*nums * sizeof(*indices));
    for (int i = 0; i < strlen(string); ++i) {
        switch (string[i]) {
            case 'a':
                indices[n] = i + 1;
                n++;
                break;
        }
    }
    return nums;
}