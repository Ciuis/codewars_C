#include <stdio.h>

typedef int (*reduce_func) (int accumulator, int value);

struct Node {
    struct Node *next;
    int data;
};

int reduce_list (const struct Node *list, reduce_func f, int init_val);

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
    int *init_val;
    reduce_func multiply;

    reduce_list(list, multiply, init_val);
}

int reduce_list (const struct Node *list, reduce_func f, int init_val) {
    int acc = init_val;

    if (list == NULL) return f(acc, list);
    while (list->next != NULL && list != NULL) {
        acc = f(acc, list->data);
        list = list->next;
    }
    if (list->next == NULL) {
        acc = f(acc, list->data);
    }

    return acc;
}