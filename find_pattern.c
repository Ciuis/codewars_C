/*For a given nonempty string s find a minimum substring t and the maximum number k, such that the entire string s is equal to t repeated k times.

The input string consists of lowercase latin letters.

Your function should return :

a tuple (t, k) (in Python)
an array [t, k] (in Ruby and JavaScript)
in C, return k and write to the string t passed in parameter

Example #1:

for string

        s = "ababab";

the answer is

("ab", 3)

Example #2:

for string

        s = "abcde"

the answer is

("abcde", 1)

because for this string "abcde" the minimum substring t, such that s is t repeated k times, is itself.*/

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t find_pattern (const char *s, char *t);
char* substr(char* string, int pos, int length);

int main() {
    char* s = "abcabc";
    char* t;
    printf("%d %s", find_pattern (s, t), t);
}

char* substr(char* string, int pos, int length) {
    char* p;
    int c;

    p = malloc(length + 1);

    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (c = 0; c < length; ++c) {
        *(p + c) = *(string + pos - 1);
        string++;
    }

    *(p + c) = 0;

    return p;
}

size_t find_pattern (const char *s, char *t) {
    int len = strlen(s);
    int j = 0;
    size_t k = 0;
    int c = 1;
    int d = 0;
    char* head; char* tail;

    for (int i = 0; i < len; ++i) {
        if (s[0] == s[i]) {
            j++;
        }

        if (j == len) {
            *t = s[0];
            k = len;
        }
    }

    for (c = 1, d = 1; c < len - 1 && d < len; ++c, ++d) {
        head = substr(s, c, d);
        tail = substr(s, c + 1, len - 1);
        if (strstr(tail, head)) {
            t = head;
            c++; d++;
        }
    }


    /*
    while(*s) {
        head = substr(s, c, d + 1);
        tail = substr(s, c + 1, len - 1);
        if (strstr(tail, head)) {
            t = head;
            c++; d++;
        }
    }
*/




    printf("%s\n", head);
    printf("%s\n", tail);

/*    for (int i = len / 2 ; i > 0; --i) {
        if (len % 2 == 0) {
            int nSubstr = len / i;
            char* tmp = substr(s, len / 2, i);

            for (int i = 0; i < nSubstr; ++i) {

            }
        }
    }*/

    *t = head; // write to t

    return k; // return k
}