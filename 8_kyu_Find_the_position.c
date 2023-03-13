/*When provided with a letter, return its position in the alphabet.

Input :: "a"

Ouput :: "Position of alphabet: 1"*/

#include <stdio.h>
#include <stdlib.h>

char* position(char alphabet) {
    char* res = (char*)malloc(100);
    int code = (int)alphabet - 96;
    sprintf(res, "Position of alphabet: %d", code);
    return res;
}