/*Write a function to convert a name into initials. This kata strictly takes two words with one space in between them.

The output should be two capital letters with a dot separating them.

It should look like this:

Sam Harris => S.H

patrick feeney => P.F*/

#include <ctype.h>

char *get_initials (const char *full_name, char initials[4]) {
    initials[0] = toupper(full_name[0]);
    initials[1] = '.';
    for (int i = 0; full_name[i] != '\0'; ++i) {
        if (full_name[i] == ' ') initials[2] = toupper(full_name[i+1]);
    }
    initials[3] = '\0';
    return initials; // return it
}

/*
char *get_initials(const char *full_name, char *initials) {
    sprintf(initials, "%c.%c", toupper(*full_name), toupper(strchr(full_name, ' ')[1]));
    return initials;
}*/
