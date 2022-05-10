#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int* indices (const char* string, size_t* nums);

int main() {
    const char* string = "abbla";
    size_t* nums = malloc(strlen(string) * sizeof(size_t));

    indices(string, nums);

    for (int i = 0; i < sizeof(nums); ++i) {
        printf("%zu ", nums[i]);
    }
}


int* indices (const char* string, size_t* nums) {
    int n = 0;
    *nums = 0;
    int *arr = malloc(*nums * sizeof(*arr));
    for (int i = 0; i < strlen(string); ++i) {
        switch (string[i]) {
            case 'a':
                arr[n++] = i + 1;
                break;
        }
    }
    return arr;
}