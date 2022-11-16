/*The action of a Caesar cipher is to replace each plaintext letter (plaintext letters are from 'a' to 'z' or from 'A' to 'Z') with a different one a fixed number of places up or down the alphabet.

This program performs a variation of the Caesar shift. The shift increases by 1 for each character (on each iteration).

If the shift is initially 1, the first character of the message to be encoded will be shifted by 1, the second character will be shifted by 2, etc...
        Coding: Parameters and return of function "movingShift"

param s: a string to be coded

        param shift: an integer giving the initial shift

The function "movingShift" first codes the entire string and then returns an array of strings containing the coded string in 5 parts (five parts because, to avoid more risks, the coded message will be given to five runners, one piece for each runner).

If possible the message will be equally divided by message length between the five runners. If this is not possible, parts 1 to 5 will have subsequently non-increasing lengths, such that parts 1 to 4 are at least as long as when evenly divided, but at most 1 longer. If the last part is the empty string this empty string must be shown in the resulting array.

For example, if the coded message has a length of 17 the five parts will have lengths of 4, 4, 4, 4, 1. The parts 1, 2, 3, 4 are evenly split and the last part of length 1 is shorter. If the length is 16 the parts will be of lengths 4, 4, 4, 4, 0. Parts 1, 2, 3, 4 are evenly split and the fifth runner will stay at home since his part is the empty string. If the length is 11, equal parts would be of length 2.2, hence parts will be of lengths 3, 3, 3, 2, 0.

You will also implement a "demovingShift" function with two parameters
Decoding: parameters and return of function "demovingShift"

an array of strings: s (possibly resulting from "movingShift", with 5 strings)

an int shift

"demovingShift" returns a string.
Example:

u = "I should have known that you would have a perfect answer for me!!!"

movingShift(u, 1) returns :

v = ["J vltasl rlhr ", "zdfog odxr ypw", " atasl rlhr p ", "gwkzzyq zntyhv", " lvz wp!!!"]

(quotes added in order to see the strings and the spaces, your program won't write these quotes, see Example Test Cases)

and demovingShift(v, 1) returns u. #Ref:

Caesar Cipher : http://en.wikipedia.org/wiki/Caesar_cipher*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char makeShift(char c, int shift);
char removeShift(char c, int shift);
int max(int x, int y);
int min(int x, int y);
char** movingShift(char* strng, int shift);
char* demovingShift(char** s, int shift);

int main() {
    char* s = "Hi";

    movingShift(s, 1);

/*    char c = 't';
    printf("%c", makeShift(c, 1));*/
}

char makeShift(char c, int shift) {
    if (c >= 65 && c <= 90) {
        return (c - 64 + shift) % 26 == 0 ? 90 : (char)(64 + (c - 64 + shift) % 26);
    }

    if (c >= 97 && c <= 122) {
        return (c - 96 + shift) % 26 == 0 ? 122 : (char)(96 + (c - 96 + shift) % 26);
    }


    return c;
}

char removeShift(char c, int shift) {
    if (c >= 65 && c <= 90) {
        return (c - 64 - shift) % 26 == 0 ? 90 : (char)(89 + (c - 89 - shift) % 26);
    }

    if (c >= 97 && c <= 122) {
        return (c - 96 - shift) % 26 == 0 ? 122 : (char)(121 + (c - 121 - shift) % 26);
    }

    return  c;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}

char** movingShift(char* strng, int shift) {
    size_t len = strlen(strng);
    int n = 0;

    char* tmpString = calloc(len + 1, sizeof(char));

    tmpString = strncpy(tmpString, strng, len);
    tmpString[len] = '\0';

    for (int i = 0; tmpString[i] != '\0'; ++i) {
        tmpString[i] = makeShift(tmpString[i], shift);
        ++shift;
        ++n;
    }

    int pLen = ceill((double)len / 5.);
    int pLens[5] = {0};

    for (int i = 0; i != 5; ++i) {
        pLens[i] = min(max(0, n - i * pLen), pLen);
    }

    char** strngArray = calloc(5, sizeof(char*));
    int idx = 0;
    for (int i = 0; i  != 5; ++i) {
        strngArray[i] = calloc(pLens[i] + 1, sizeof(char));
        memcpy(strngArray[i], &tmpString[idx], pLens[i]);
        idx += pLens[i];
        strngArray[i][pLens[i]] = '\0';

        printf("%s\n", strngArray[i]);
    }

    return strngArray;

}

char* demovingShift(char** s, int shift) {
    unsigned n = 0;
    unsigned len = 0;

    for (int i = 0; i != 5; ++i) {
        n += strlen(s[i] + 1);
    }

    char* strng = malloc(n * sizeof(char));
    strng[0] = '\0';

    for (int i = 0; i != 5; ++i) {
        n = strlen(s[i]);
        strncpy(&strng[len], s[i], n);
        len += n;
        strng[len] = '\0';
    }

    for (int i = 0; strng[i] != '\0'; ++i) {
        strng[i] = removeShift(strng[i], shift);
        ++shift;
    }

    return strng;
}