/*
Write a function that doubles every second integer in a list, starting from the left.
Example:
For input array/list :
[1,2,3,4]
the function should return :
[1,4,3,8]
 */

#include <stddef.h>

void double_every_other (size_t length, int array[length]) {
    for (int i = 0; i < length; i += 2) array[i] *= 2;
}
