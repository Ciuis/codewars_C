/*Remove n exclamation marks in the sentence from left to right. n is positive integer.
Examples

remove("Hi!",1) === "Hi"
remove("Hi!",100) === "Hi"
remove("Hi!!!",1) === "Hi!!"
remove("Hi!!!",100) === "Hi"
remove("!Hi",1) === "Hi"
remove("!Hi!",1) === "Hi!"
remove("!Hi!",100) === "Hi"
remove("!!!Hi !!hi!!! !hi",1) === "!!Hi !!hi!!! !hi"
remove("!!!Hi !!hi!!! !hi",3) === "Hi !!hi!!! !hi"
remove("!!!Hi !!hi!!! !hi",5) === "Hi hi!!! !hi"
remove("!!!Hi !!hi!!! !hi",100) === "Hi hi hi"*/

#include <stdlib.h>
#include <string.h>

char *rem_c(const char *str_in, int n) {
    char *r = malloc(strlen(str_in) + 1);
    int l = 0, m = 0, k = 0;

    while(str_in[m] != '\0') {
        if (str_in[m] == '!' && l < n) {
            ++m;
            ++l;
        } else {
            r[k] = str_in[m];
            ++m;
            ++k;
        }
    }
    r[k] = '\0';

    return r;
}

