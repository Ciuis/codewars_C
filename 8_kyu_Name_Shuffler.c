/*
Write a function that returns a string in which firstname is swapped with last name.

Example(Input --> Output)

"john McClane" --> "McClane john"
*/

#include <string.h>
#include <stdio.h>


char *name_shuffler (char *shuffled, const char *name) {
    char* tmp = strdup(name);
    char* first = strtok(tmp, " ");
    char* second = strtok(NULL, " ");

    sprintf(shuffled, "%s %s", second, first);

    return shuffled;
}