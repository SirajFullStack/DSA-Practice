#include "BST.h"

bool BST::search(Node* node, int target) {
    if (!node) return false;
    if (node->data == target) return true;

    if (node->data < target)
        return search(node->right, target);   // fixed: was node->left
    else
        return search(node->left, target);    // fixed: was node->right
}

bool BST::search(int v) { return search(root, v); }
