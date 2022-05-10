#include <stdio.h>

typedef struct node_t {
    void *data;
    struct node_t *next;
} Node;

int length(const Node *head) {
    if (head == NULL) {
        return 0;
    } else {
        return length(head->next) + 1;
    }
}