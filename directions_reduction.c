// arr: directions to reduce, sz: size of arr, lg size of returned array
// function result will be freed
#include <stdio.h>
#include <ctype.h>

char** dirReduc(char** arr, int sz, int* lg);

int main() {
    int lg;
    char* dir[] = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
    dirReduc(dir, 6, &lg);
}

char** dirReduc(char** arr, int sz, int* lg) {
    for (; **arr; *arr++) {
        for(; *arr; arr++) {
            *arr = (char)tolower(*arr);
        }
    }

    sz = 0;
    *lg = 0;
    return arr;
}