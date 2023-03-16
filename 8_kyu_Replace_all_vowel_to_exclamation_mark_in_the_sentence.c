/*
Replace all vowel to exclamation mark in the sentence. aeiouAEIOU is vowel.
Examples

replace("Hi!") === "H!!"
replace("!Hi! Hi!") === "!H!! H!!"
replace("aeiou") === "!!!!!"
replace("ABCDE") === "!BCD!"
*/
#include <stdlib.h>
#include <string.h>


char *replace(const char *s) {
    char* rep = (char*)malloc(sizeof(s));
    strcpy(rep, s);

    for (int i = 0; rep[i] != '\0'; ++i) {
        switch(rep[i]) {
        case 'a': case 'e': case 'i': case 'o': case 'u': case 'y': case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y':
                rep[i] = '!';
        }
    }



    return rep;
}