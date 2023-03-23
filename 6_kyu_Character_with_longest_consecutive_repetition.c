/*
For a given string s find the character c (or C) with longest consecutive repetition and return:

c
(assign l to pointer)

where l (or L) is the length of the repetition. If there are two or more characters with the same l return the first in order of appearance.

For empty string return:

'\0'
(assign 0 to pointer)
*/

//  return the character with longest consecutive repetition
//  if the string is empty, return a null terminator: '\0'
//  assign the count of repetitions to the provided pointer *n

#include <stddef.h>


char longest_repetition(const char *s, size_t *n) {
    int max = 0;
    char c = '\0';

    for (int i = 0; s[i] != '\0';) {
        int cnt = 1;
        while (s[i] == s[i + cnt]) ++cnt;;
        if (cnt > max) {
            max = cnt;
            c = s[i];
        }
        i += cnt;
    }

    *n = max;
    return c;
}