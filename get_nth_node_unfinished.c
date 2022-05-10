#include <stddef.h>

struct List {
    struct List *next;
    int data;
};

struct List *get_nth_node (const struct List *list, size_t n);

int main() {

    struct List list;

}

// return the nth node, or NULL if n >= length(list)
struct List *get_nth_node (const struct List *list, size_t n) {
    if (*list == NULL)

    return list;
}