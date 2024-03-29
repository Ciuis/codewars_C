/*
Challenge: Most of us had to come across the "strtok" function of the C standard library at one point or another: http://www.cplusplus.com/reference/cstring/strtok/

For this kata, we have to implement it ourselves!

The purpose of this function is, given a (writeable) source string and a string of delimiters, to "tokenize" the source string. The best analogy could be the "strip" function in other high-level languages.

Please, pay attention to the peculiarity of use of this function. The first call to "strtok" "tokenizes" the function, i.e. splits it into tokens by placing the null-terminating character where any of the delimiters is found. At the end of the call, the first token of the string is returned. Each subsequent call to "strtok" should have NULL in place where the source string was, in order for the function to return a subsequent token. Once we run out of tokens, "strtok" returns a NULL. (For a more visual example, please consult the Example section below)

Before submitting the solution, please make sure that your function follows the exact same behavior as the original "strtok" function from the C standard library.

Example:

char buffer[] = "I did it MY way!";
const char *DELIMITERS = " ";
char *token = my_strtok(buffer, DELIMITERS);
while (token) {
(void)printf("%s, "token);
token = my_strtok(NULL, DELIMITERS);
}
*/
/*
 outputs: I, did, it, MY, way!
*//*


Addendum: In order to successfully complete this kata, please make sure you are familiar with static variables in C. The basic idea is as follows:

int foo(void) {
    static int x;
    return x++;
}

int main(void) {
    for (int i = 0; i < 5; ++i) {
        int value = foo();
        (void)printf("%d\n", value);
    }
    // outputs: 0 1 2 3 4

    return 0;
}

PLEASE NOTICE! The number of tests for one string will be equal to n + 1, where n is the number of tokens created by strtok and + 1 is the extra check to test whether both functions have indeed completed their tokenization at the same point in the source string. Thus char src[] = "hello there universe" with the delimiters set to const char *delims = " "; will produce 4 tests.
*/

#include <stddef.h>
#include <string.h>
#include <stdio.h>

char* my_strtok(char *src, const char *delims);

int main() {
    char buffer[] = "I did it MY way!";
    const char* delim = " ";
}


char* my_strtok(char *src, const char *delims) {
    static char *token = NULL;

    if (src != NULL) {
        token = src;
    } else if (token == NULL) {
        return NULL;
    } else {
        src = token;
    }

    for (; index(delims, *token) != NULL; token++) {
        if (*token == '\0') {
            return NULL;
        }
    }

    for (src = token; index(delims, *token) == NULL; token++) {
        ;
    }

    if (*token == '\0') {
        token = NULL;
    } else {
        *(token++) = '\0';
    }

    return src;
}


/*
#define _POSIX_SOURCE
#include <string.h>

char* my_strtok(char *src, const char *delims) {
  static char *state;
  return strtok_r(src, delims, &state);
}

 static char *next = NULL;
assert(src || next);
assert(delims);
if (!src)
    src = next;
src += strspn(src, delims);
if (!*src)
    return ((next = NULL));
next = src + strcspn(src, delims);
*next++ = '\0';
return src;
 */
