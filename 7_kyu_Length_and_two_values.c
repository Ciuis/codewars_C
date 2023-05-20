/*Given an integer n and two other values, build an array of size n filled with these two values alternating.
Examples

5, true, false     -->  [true, false, true, false, true]
10, "blue", "red"  -->  ["blue", "red", "blue", "red", "blue", "red", "blue", "red", "blue", "red"]
0, "one", "two"    -->  []*/

#include <stddef.h>

void alternate(size_t length, int first_value, int second_value, int *array) {
    for (size_t i = 0; i < length; i+=2) {
        array[i] = first_value;
        for (size_t j = i + 1; j < length; ++j) {
            array[j] = second_value;
        }
    }
}


/*
void
alternate(size_t length, int first_value, int second_value, int *array) {
    for (size_t i = 0; i < length; ++i) {
        array[i] = (const int[]) { first_value, second_value }[i & 1];
    }
}*/
