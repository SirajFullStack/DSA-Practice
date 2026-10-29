#include "BST.h"

void BST::count_leaf(Node* node, int& count) {
    if (!node) return;
    if (!node->left && !node->right)
        count++;
    count_leaf(node->left, count);
    count_leaf(node->right, count);
}

int BST::count_leaf() {
    int count = 0;
    count_leaf(root, count);
    return count;
}
