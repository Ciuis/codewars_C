#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* parse(char* program);

int main() {
    char* program = "isoisoiso";
    int* nums = parse(program);

    for(int i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i) {
        printf("%d ", nums[i]);
    }
}

int* parse(char* program) {
    int prints = 0;
    for (int i = 0; i < strlen(program); ++i) {
        if (program[i] == 'o') {
            prints++;
        }
    }

    int* parsed = malloc(sizeof(int) * prints);

    int value = 0;
    int j = 0;
    for (int i = 0; i < strlen(program); ++i) {

        if (program[i] == 'i') value += 1;
        if (program[i] == 'd') value -= 1;
        if (program[i] == 's') value *= value;
        if (program[i] == 'o') {
            parsed[j] = value;
            j++;
        }
    }

    return parsed;
}
