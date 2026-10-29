#include "BST.h"

int BST::Height(Node* node) {
    if (!node) return -1;
    int lh = Height(node->left);
    int rh = Height(node->right);
    return (lh > rh ? lh : rh) + 1;
}

int BST::Height() { return Height(root); }
