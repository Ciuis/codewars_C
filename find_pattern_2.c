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
#include <stdlib.h>
#include <string.h>

size_t find_pattern (const char *s, char *t);

int main() {
    char* s = "ababab";
    char* t = malloc(sizeof(char) * sizeof(*t));

    find_pattern (s, t);

    printf("%s", t);
}

size_t find_pattern (const char *s, char *t) {
    size_t k = 0;
    char* r = 0, *a = s;
    *t = 0;

    while (*a) {
        char* e = strchr(a + 1, *a);
        if (!e) {
            break;
        }
        do {
            k = 1;
            for (; &a[k] != e && a[k] == e[k]; ++k);
            if (k > 0)
                *t = e, r = a;
            while (--e != a && *e != *a);
        } while (e != a && *e == *a);

        ++a;
    }

    return k; // return k
}
