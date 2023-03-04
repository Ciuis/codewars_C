/*
Build a function that returns an array of integers from n to 1 where n>0.

Example : n=5 --> [5,4,3,2,1]
Note: allocate memory yourself */

#include <stdlib.h>
#include <stdio.h>

unsigned short *reverse_seq(unsigned short num);

int main(void) {
    int n = 10;
    reverse_seq(n);

}

unsigned short *reverse_seq(unsigned short num) {
    unsigned short* arr = calloc(num, sizeof(unsigned short));
    for(unsigned short i = 0; i < num; ++i) {
        arr[i] = num - i;
        printf("%d", arr[i]);
    }
    return arr;
}