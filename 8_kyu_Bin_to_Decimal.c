// Complete the function which converts a binary number (given as a string) to a decimal number.

#include <string.h>
#include <math.h>

unsigned bin_to_decimal(const char *bin) {
    unsigned res = 0;
    for (unsigned i = 0; i < strlen(bin); ++i) {
        if (bin[i] == '1') res += pow(2, strlen(bin) - 1 - i);
    }
    return res;
}
