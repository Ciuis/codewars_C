/*
write me a function stringy that takes a size and returns a string of alternating 1s and 0s.

the string should start with a 1.

a string with size 6 should return :'101010'.

with size 4 should return : '1010'.

with size 12 should return : '101010101010'.

The size will always be positive and will only use whole numbers.*/

#include <stdlib.h>
#include <stdio.h>

char *stringy (size_t size) {
    char* s = calloc(sizeof(char), size);
    for (int i = 0; i < size; i += 2) s[i] = '1';
    for (int j = 1; j < size; j += 2) s[j] = '0';
    s[size] = '\0';
    return s;
}