/*
Write a function that will check if two given characters are the same case.

If either of the characters is not a letter, return -1
If both characters are the same case, return 1
If both characters are letters, but not the same case, return 0

Examples

'a' and 'g' returns 1

'A' and 'C' returns 1

'b' and 'G' returns 0

'B' and 'g' returns 0

'0' and '?' returns -1
*/

#include <stdio.h>
#include <ctype.h>

int same_case (char a, char b);

int main() {
    char a = '^';
    char b = 'F';
    printf("%d\n", same_case (a, b));
}


int same_case (char a, char b) {
    if (!isalpha(a) || !isalpha(b)) return -1;
    if ((a <= 'Z' && b <= 'Z') || (a >= 'a' && b >= a)) {
        return 1;
    }
    return 0;
}