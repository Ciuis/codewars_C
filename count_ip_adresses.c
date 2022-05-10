/*
Implement a function that receives two IPv4 addresses, and returns the number of addresses between them (including the first one, excluding the last one).

All inputs will be valid IPv4 addresses in the form of strings. The last address will always be greater than the first one.
Examples

* With input "10.0.0.0", "10.0.0.50"  => return   50
* With input "10.0.0.0", "10.0.1.0"   => return  256
* With input "20.0.0.10", "20.0.1.0"  => return  246*/

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int str2int(char* s, int* arr);
uint32_t ips_between (const char *start, const char *end);

int main() {
    const char* start = "0.0.0.0";
    const char* end = "255.255.255.255";

    printf("%d\n", ips_between(start, end));

}

int str2int(char* s, int* arr) {
    char* endptr = s, *ptr = s;
    int cnt = 0;

    while(*endptr != '\0') {
        if(isdigit(*ptr)) {
            arr[cnt++] = strtol(ptr, &endptr, 10);
        } else {
            endptr = ptr + 1;
        }
    }

    ptr = endptr;
}

uint32_t ips_between (const char *start, const char *end) {
    //uint32_t result = 0;
    int* s = malloc(sizeof(uint32_t));
    int* e = malloc(sizeof(uint32_t));

    *s = str2int(start, s);
    *e = str2int(end, e);

    printf("\ns[0] = %d\ne[0] = %d\n", s[0], e[0]);

    uint32_t result = (e[0] - s[0]) * 256 * 256 * 256;
    printf("[0]: %d\n", result);
    result += (e[1] - s[1]) * 256 * 256;
    printf("[1]: %d\n", result);
    result += (e[2] - s[2]) * 256;
    printf("[2]: %d\n", result);
    result += (e[3] - s[3]);
    printf("[3]: %d\n", result);

    return result;
}
