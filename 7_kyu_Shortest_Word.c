/*
Simple, given a string of words, return the length of the shortest word(s).

String will never be empty and you do not need to account for different data types.*/

#include <sys/types.h>

ssize_t find_short(const char *s) {
    ssize_t result = 9999;
    ssize_t tmp = 0;
    while (*s != '\0') {
        if (*s != ' ') {
            tmp = 0;
            while(*s != ' ' && *s != '\0') {
                tmp++;
                s++;
            }
            if (tmp < result) result = tmp;
        } else s++;
    }
    return result;
}
