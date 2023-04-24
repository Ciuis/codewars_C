// Create a method that accepts a list and an item, and returns true if the item belongs to the list, otherwise false.

#include <stdbool.h>
#include <stddef.h>

bool include(const int* arr, size_t size, int item) {
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == item) return true;
    }
    return false;
}



//bool include (const int* a, size_t n, int e) { return n>0 && (*a==e || include (a+1, n-1, e)); }