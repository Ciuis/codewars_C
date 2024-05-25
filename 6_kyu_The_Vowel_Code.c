/*Step 1: Create a function called encode() to replace all the lowercase vowels in a given string with numbers according to the following pattern:
a -> 1
e -> 2
i -> 3
o -> 4
u -> 5
For example, encode("hello") would return "h2ll4". There is no need to worry about uppercase vowels in this kata.
Step 2: Now create a function called decode() to turn the numbers back into vowels according to the same pattern shown above.
For example, decode("h3 th2r2") would return "hi there".
For the sake of simplicity, you can assume that any numbers passed into the function will correspond to vowels.*/

#include <stdlib.h>
#include <string.h>

char *encode(const char *string) {
    char* result = malloc(strlen(string) + 1);
    strcpy(result, string);

    for (int i = 0; result[i] != '\0'; ++i) {
        switch(result[i]) {
            case 'a':
                result[i] = '1';
                break;
            case 'e':
                result[i] = '2';
                break;
            case 'i':
                result[i] = '3';
                break;
            case 'o':
                result[i] = '4';
                break;
            case 'u':
                result[i] = '5';
                break;
        }
    }

    result[strlen(result)] = '\0';
    return result;
}

char *decode(const char *string) {
    char* result = malloc(strlen(string) + 1);
    strcpy(result, string);

    for (int i = 0; result[i] != '\0'; ++i) {
        switch(result[i]) {
            case '1':
                result[i] = 'a';
                break;
            case '2':
                result[i] = 'e';
                break;
            case '3':
                result[i] = 'i';
                break;
            case '4':
                result[i] = 'o';
                break;
            case '5':
                result[i] = 'u';
                break;
        }
    }

    result[strlen(result)] = '\0';
    return result;
}