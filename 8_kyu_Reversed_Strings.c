/*
Complete the solution so that it reverses the string passed into it.

'world'  =>  'dlrow'
'word'   =>  'drow'
*/
#include <string.h>


char *strrev (char *string) {

    for (size_t i = 0, j = strlen(string) - 1; i < j; i++, j--) {
        char t = string[i];
        string[i] = string[j];
        string[j] = t;
    }

    return string; // reverse the string in place and return it
}