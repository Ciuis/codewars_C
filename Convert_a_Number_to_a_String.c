/*We need a function that can transform a number (integer) into a string.

What ways of achieving this do you know?

In C, return a dynamically allocated string that will be freed by the test suite.
Examples (input --> output):

123  --> "123"
999  --> "999"
-100 --> "-100"*/


#include <stdlib.h>
#include <stdio.h>

char *number_to_string(int number) {
    char* nts = (char*)calloc(20, sizeof(int));
    sprintf(nts, "%d", number);
    return  nts;
}
