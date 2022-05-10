/*
Linked Lists - Length & Count

        Implement Length() to count the number of nodes in a linked list.

length(null) => 0
length(1 -> 2 -> 3 -> null) => 3

Implement Count() to count the occurrences of an integer in a linked list.

count(null, 1) => 0
count(1 -> 2 -> 3 -> null, 1) => 1
count(1 -> 1 -> 1 -> 2 -> 2 -> 2 -> 2 -> 3 -> 3 -> null, 2) => 4
*/

/*
best practice:

#include <stddef.h>

typedef struct Node {
    struct Node *next;
    int value;
} Node;

size_t list_length (const Node *node)
{
    return node ? 1 + list_length(node->next) : 0;
}

size_t list_count (const Node *node, int val)
{
    return node ? (node->value == val) + list_count(node->next, val) : 0;
}*/


#include <stddef.h>
#include <stdio.h>

struct Node {
    struct Node *next;
    int value;
};

size_t list_length (const struct Node *list);
size_t list_count (const struct Node *list, int search_val);

int main() {
    struct Node* list = &(struct Node) {.value = 666, .next = &
            (struct Node) {.value = 666, .next = &
                    (struct Node) {.value = 666, .next = &
                            (struct Node) {.value = 666, .next = &
                                    (struct Node) {.value = 666, .next = &
                                            (struct Node) {.value = 666, .next = NULL}
                                    }
                            }
                    }
            }
    };
    printf("%zu\n", list_length(list));
    printf("%zu", list_count(list, 666));
}

// returns the length of the list
size_t list_length (const struct Node *list) {
    if (list == NULL) {
        return 0;
    } else {
        return list_length(list->next) + 1;
    }
}

// returns the number of occurences of search_val in list
size_t list_count (const struct Node *list, int search_val) {
    int cnt = 0;
    if (list == NULL) return 0;

    for (int i = 0; i < list_length(list) * 256; ++i) {
        if (list->value == search_val) {
            cnt += 1;
        }
        list = list->next;
    }
    return cnt;
}