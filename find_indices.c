#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* indices (const char* string, size_t* nums) {
    int n = 0;
    for (int i = 0; i < strlen(string); ++i) {
        switch (string[i]) {
            case 'a':
                nums[n] = i + 1;
                n++;
                break;
        }
    }
    return nums;
}
