/*Complete the solution so that it reverses all of the words within the string passed in.

Words are separated by exactly one space and there are no leading or trailing spaces.


'words' is nul-terminated, but its 'length' is given for convenience.
Write to 'reversed' and return it.


Example(Input --> Output):

"The greatest victory is that which requires no battle" --> "battle no requires which that is victory greatest The"*/

#include <stddef.h>
#include <string.h>


void reverse(char* begin, char* end) {
    for (--end; begin < end; ++begin, --end) {
        char ch = *begin;
        *begin = *end;
        *end = ch;
    }
}

char* reverse_words (const char *words, size_t length, char *reversed) {
    strcpy(reversed, words);
    char* begin = reversed;
    do {
        for (; *begin == ' '; ++begin);
        if (*begin == '\0') break;

        char* end = begin;
        for (++end; *end != '\0' && *end != ' '; ++end);

        reverse(begin, end);
        begin = end;
    } while (1);

    reverse(reversed, begin);

    return reversed;
}