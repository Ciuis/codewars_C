/*Count the number of Duplicates

        Write a function that will return the count of distinct case-insensitive alphabetic characters and numeric digits that occur more than once in the input string. The input string can be assumed to contain only alphabets (both uppercase and lowercase) and numeric digits.
Example

"abcde" -> 0 # no characters repeats more than once
"aabbcde" -> 2 # 'a' and 'b'
"aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
"indivisibility" -> 1 # 'i' occurs six times
"Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
"aA11" -> 2 # 'a' and '1'
"ABBA" -> 2 # 'A' and 'B' each occur twice*/

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

size_t duplicate_count(const char *text);

int main() {
    char* text = "indivisibility";
    duplicate_count(text);
}

size_t duplicate_count(const char *text) {
    size_t cnt = 0;
    char arr[256] = {0};

    for (int i = 0; i < strlen(text); ++i) {
        ++arr[text[i]];
        printf("%d\n", arr[i]);
    }

    for (int i = 0; i < 256; ++i) {
        if (arr[i] > 1) {
            cnt++;
        }
    }
    printf("%zu", cnt);
}