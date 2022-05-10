#include <stdio.h>
#include <stdlib.h>

void twoSum(unsigned count, const int numbers[count], int target,
            unsigned *index1, unsigned *index2);

int main() {
    int nums[] = {1, 2, 3};
    unsigned count = sizeof(nums) / sizeof(nums[0]);
    int target = 4;
    unsigned *index1, *index2 = malloc(sizeof(unsigned));
    printf("%d\n", count);

    twoSum(count, nums, target, *index1, *index2);
}

void twoSum(unsigned count, const int numbers[count], int target,
            unsigned *index1, unsigned *index2) {
// assign to the index1 and index2 pointers

    for (int i = 0; i < count; ++i) {
        for (int k = i + 1; k < count; ++k) {
            if (numbers[i] + numbers[k] == target) {
                *index1 = numbers[i];
                *index2 = numbers[k];
            }
        }
    }

    printf("%d %d", *index1, *index2);
}