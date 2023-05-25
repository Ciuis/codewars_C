/*Write Number in Expanded Form

        You will be given a number and you will need to return it as a string in Expanded Form. For example:

expandedForm 12    -- Should return '10 + 2'
expandedForm 42    -- Should return '40 + 2'
expandedForm 70304 -- Should return '70000 + 300 + 4'

NOTE: All numbers will be whole numbers greater than 0.*/

#include <math.h>
#include <stdio.h>
#include <string.h>


char *expandedForm(char *string, unsigned long long n) {
    string[0] = '\0';
    int i = 1;
    char token[999];
    unsigned long long m = n;
    unsigned long long res = 0;
    while(m /= 10) ++i;

    unsigned long long temp = n;

    for (unsigned j = i; j > 0; --j) {
        res = (temp / (unsigned long long)pow(10, j - 1)) * 1 * (unsigned long long)pow(10, j - 1);
        if (res != 0) {
            sprintf(token, "%llu + ", res);
            strcat(string, token);
        }
        temp = temp - res;
    }

    string[strlen(string) - 3] = '\0';

    return string;
}