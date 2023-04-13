/*
Create a function which answers the question "Are you playing banjo?".
If your name starts with the letter "R" or lower case "r", you are playing banjo!

The function takes a name as its only argument, and returns one of the following strings:

name + " plays banjo"
name + " does not play banjo"

Names given are always valid strings.
*/

#include <stdlib.h>
#include <ctype.h.>
#include <string.h>

char *are_you_playing_banjo(const char *name) {
    char* res = (char*)malloc(strlen(name) * sizeof(char) + 20);
    strcpy(res, name);
    return tolower(name[0]) == 'r' ? strcat(res, " plays banjo" ) : strcat(res, " does not play banjo");
}