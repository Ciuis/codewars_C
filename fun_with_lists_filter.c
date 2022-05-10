/*
Implement the method filter, which accepts a linked list (head) and a predicate function, and returns a new linked list (head) which only contains the elements which apply to the given predicate.

For example: Given the list: 1 -> 2 -> 3, and the predicate x => x >= 2, filter should return 2 -> 3, since x >= 2 applies to both 2 and 3.

The linked list is defined as follows:

struct Node {
    struct Node *next;
    int data;
};

Note: the list may be null and can hold any type of value.*/

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *next;
    int data;
};

typedef bool (*predicate_func) (int);

static bool is_odd (int x)
{
    return x % 2;
}

static bool is_even (int x)
{
    return !(x % 2);
}

struct Node *filter_list (const struct Node *list, predicate_func f);

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

    filter_list(list, is_even);
}

/* return a fresh new list
   allocate each node on the heap, so that the list can be freed recursively
   do not mutate or re-use the input list
*/

struct Node *filter_list (const struct Node *list, predicate_func f) {
    struct Node *filteredList = (struct Node*)malloc(sizeof(struct Node));
    if (list == NULL) return NULL;
    if (f(list->data)) {
        filteredList->data = list->data;
        filteredList->next = filter_list(list->next, f);
    } else {
        return filter_list(list->next, f);
    }

    return filteredList;
}
