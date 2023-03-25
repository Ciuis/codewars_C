/*Consider an array/list of sheep where some sheep may be missing from their place. We need a function that counts the number of sheep present in the array (true means present).

For example,

{ true,  true,  true,  false,
true,  true,  true,  true,
true,  false, true,  false,
true,  false, false, true,
true,  true,  true,  true,
false, false, true,  true }

The correct answer would be 17.

Hint: Don't forget to check for bad values like null/undefined*/

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

size_t count_sheep(const bool sheep[/* count */], size_t count);

int main(void) {
    bool sheeps[] = { true,  true,  true,  false,
                      true,  true,  true,  true,
                      true,  false, true,  false,
                      true,  false, false, true,
                      true,  true,  true,  true,
                      false, false, true,  true };
    size_t count = 24;

    printf("%d", count_sheep(sheeps, count));
}

size_t count_sheep(const bool sheep[/* count */], size_t count) {
    size_t res = 0;

    while (count > 0) {
        *sheep++ == true ? res += 1 : res;
        --count;
    }
    return res;
}

/*
size_t count_sheep(const bool *sheep, size_t count)
{
    int sum = 0;
    for (; count--; sum += *sheep++);
    return sum;
}*/
