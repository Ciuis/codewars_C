/*You are given a string of letters and an array of numbers.
The numbers indicate positions of letters that must be removed, in order, starting from the beginning of the array.
After each removal the size of the string decreases (there is no empty space).
Return the only letter left.

Example:

let str = "zbk", arr = [0, 1]
str = "bk", arr = [1]
str = "b", arr = []
return 'b'

Notes

The given string will never be empty.
The length of the array is always one less than the length of the string.
All numbers are valid.
There can be duplicate letters and numbers.*/


#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void del_char(char* str, size_t idx);
char last_survivor (const char *letters, size_t nb_indexes, const size_t indexes[nb_indexes]);

int main() {
    const char* letters = "abcdefgh";
    size_t nb_indexes = 7;
    size_t indexes[7] = {0, 1, 2, 3, 2, 1, 0};

    char c = last_survivor(letters, nb_indexes, indexes);

    printf("%c\n", c);
}

void del_char(char* str, size_t idx) {
    size_t i = 0;
    for (i = idx; i < strlen(str); ++i) {
        str[i] = str[i+1];
    }
}

char last_survivor (const char *letters, size_t nb_indexes, const size_t indexes[nb_indexes]) {
    char* tmp = malloc(strlen(letters) * sizeof(char));
    for (int i = 0; letters[i] != '\0'; ++i) {
        tmp[i] = letters[i];
    }

    tmp[strlen(letters)] = '\0';



    for (size_t i = 0; i < nb_indexes; ++i) {
        del_char(tmp, indexes[i]);
    }

    char c = tmp[0];



    return c;
}