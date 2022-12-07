/*
An isogram is a word that has no repeating letters, consecutive or non-consecutive. Implement a function that determines whether a string that contains only letters is an isogram. Assume the empty string is an isogram. Ignore letter case.

Example: (Input --> Output)

"Dermatoglyphics" --> true "aba" --> false "moOse" --> false (ignore letter case)

isIsogram "Dermatoglyphics" = true
        isIsogram "moose" = false
        isIsogram "aba" = false
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool IsIsogram (const char *string);

int main() {
    const char* string = "abcde";

    printf("%d", IsIsogram(string));
}

bool IsIsogram (const char *string) {

    for (int i = 0; string[i] != '\0'; ++i) {
        for (int j = i + 1; j < strlen(string); ++j) {
            if (tolower(string[i]) == tolower(string[j])) {
                return false;
            }
        }
    }
    return true;
}

