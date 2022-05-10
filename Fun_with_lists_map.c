/*
Implement the method map, which accepts a linked list (head) and a mapping function, and returns a new linked list (head) where every element is the result of applying the given mapping method to each element of the original list.

For example: Given the list: 1 -> 2 -> 3, and the mapping function x => x * 2, map should return 2 -> 4 -> 6

The linked list is defined as follows:

struct Node {
    struct Node *next;
    int data;
};

Note: the list may be null and can hold any type of value.*/

#include <stddef.h>
#include <stdlib.h>

struct Node {
    struct Node *next;
    int data;
};

typedef int (*map_func) (int);

static int times_two (int x) {
    return x * 2;
}

struct Node *map_list (const struct Node *list, map_func f);

int main() {
    struct Node *list = &
            (struct Node) {.data = 5, .next = &
                    (struct Node) {.data = 21, .next = &
                            (struct Node) {.data = -7, .next = &
                                    (struct Node) {.data = 48, .next = &
                                            (struct Node) {.data = 32, .next = &
                                                    (struct Node) {.data = 15, .next = NULL}
                                            }
                                    }
                            }
                    }
            };

    map_list(list, times_two);
}

/* return a fresh new list
   allocate each node on the heap, so that the list can be freed recursively
   do not mutate or re-use the input list
*/

struct Node *map_list (const struct Node *list, map_func f) {
    struct Node *mappedList = (struct Node*)malloc(sizeof(struct Node));
    if (list == NULL) return NULL;

    mappedList->data = f(list->data);
    mappedList->next = map_list(list->next, f);

    return mappedList;
}