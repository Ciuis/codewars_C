/*Complete the function scramble(str1, str2) that returns true if a portion of str1 characters can be rearranged to match str2, otherwise returns false.

Notes:

Only lower case letters will be used (a-z). No punctuation or digits will be included.
Performance needs to be considered.

Input strings s1 and s2 are null terminated.

Examples

scramble('rkqodlw', 'world') ==> True
scramble('cedewaraaossoqqyt', 'codewars') ==> True
scramble('katas', 'steak') ==> False*/


#include <stdbool.h>

bool scramble(const char *str1, const char *str2) {
    int counter[26] = {0};

    for (int i = 0; str1[i] != '\0'; ++i) {
        counter[str1[i] - 'a']++;
    }

    for (int j = 0; str2[j] != '\0'; ++j) {
        if (counter[str2[j] - 'a'] == 0) return false;
        counter[str2[j] - 'a']--;
    }
    return true;
}


/*
#include <limits.h>
#include <stdbool.h>

bool scramble(const char *str1, const char *str2)
{
    int count1[CHAR_MAX - CHAR_MIN + 1] = {0};
    for (; *str1; ++str1) ++count1[*str1 - CHAR_MIN];
    for (; *str2; ++str2)
        if (--count1[*str2 - CHAR_MIN] < 0)
            return false;
    return true;
}
 */

/* Tooooooo slooooooow
    int compare(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

bool scramble(const char *str1, const char *str2) {
    char* alter_s1 = (char*)calloc(strlen(str1) + 1, sizeof(char));
    strcpy(alter_s1, str1);
    char* alter_s2 = (char*)calloc(strlen(str2) + 1, sizeof(char));
    strcpy(alter_s2, str2);

    if (strlen(alter_s2) > strlen(alter_s1)) return false;
    qsort(alter_s1, strlen(alter_s1), sizeof(char), compare);
    qsort(alter_s2, strlen(alter_s2), sizeof(char), compare);

    size_t i = 0;
    size_t j = 0;

    for (; i < strlen(alter_s1) && j < strlen(alter_s2);) {
        if (alter_s1[i] == alter_s2[j]) {
            ++i;
            ++j;
        } else {
            ++i;
        }
    }
    return j == strlen(alter_s2);
}*/