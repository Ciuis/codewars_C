#include <stdbool.h>
#include <stdio.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

bool equal_trees(const TreeNode *a, const TreeNode *b);

int main() {
    TreeNode a = {1, NULL, NULL};
    TreeNode b = {1, NULL, NULL};
    TreeNode c = {2, NULL, NULL};

    printf("%d\n", equal_trees(&a, &c));
}


bool equal_trees(const TreeNode *a, const TreeNode *b) {
    if (a == NULL && b == NULL) {
        return true;
    } else if (a != NULL && b != NULL) {
        return (a->val == b->val && equal_trees(a->left, b->left) && equal_trees(a->right, b->right));
    } else {
        return false;
    }
}