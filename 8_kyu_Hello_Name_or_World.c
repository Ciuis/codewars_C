/*
Define a method hello that returns "Hello, Name!" to a given name, or says Hello, World! if name is not given (or passed as an empty String).

Assuming that name is a String and it checks for user typos to return a name with a first capital letter (Xxxx).

Examples:

* With `name` = "john"  => return "Hello, John!"
* With `name` = "aliCE" => return "Hello, Alice!"
* With `name` not given
or `name` = ""        => return "Hello, World!"
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *hello(const char *name);

int main(void) {
    char* name = "John";
    printf("%s", hello(name));
}

char *hello(const char *name) {
    char* str = malloc(strlen(name) + 1);
    char* result = malloc(strlen(name) + 1);

    if (name == NULL || name[0] == '\0') {
        str = "World";
    } else {
        str[0] = toupper(name[0]);
        for (int i = 1; name[i] != '\0'; i++) {
            str[i] = tolower(name[i]);
        }
    }
    sprintf(result, "Hello, %s!", str);
    return result;
}