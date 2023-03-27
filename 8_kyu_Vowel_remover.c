/*Create a function called shortcut to remove the lowercase vowels (a, e, i, o, u ) in a given string.
Examples

"hello"     -->  "hll"
"codewars"  -->  "cdwrs"
"goodbye"   -->  "gdby"
"HELLO"     -->  "HELLO"

don't worry about uppercase vowels
y is not considered a vowel for this kata*/

#include <string.h>
char vowels[] = {'a', 'e', 'i', 'o', 'u'};


char *shortcut (char *str_out, const char *str_in) {
    int j = 0;
    for (int i = 0; str_in[i]; ++i) {
        if (!strchr(vowels, str_in[i])) str_out[j++] = str_in[i];
        }
    str_out[j] = 0;
    return str_out;
}