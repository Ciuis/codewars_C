/*Define a function that removes duplicates from an array of numbers and returns it as a result.

The order of the sequence has to stay the same.*/

#include <stdlib.h>

int *distinct(const int *values, size_t count, size_t *pResultCount) {
    *pResultCount = 0;
    int* result = (int*)calloc(count, sizeof(values[0]));

    for (size_t i = 0; i < count; ++i) {
        int is_duplicate = 0;

        for (size_t j = 0; j < *pResultCount; ++j) {
            if (values[i] == result[j]) {
                is_duplicate = 1;
                break;
            }
        }

        if (is_duplicate == 0) {
            result[*pResultCount] = values[i];
            (*pResultCount)++;
        }
    }

    return result;
}