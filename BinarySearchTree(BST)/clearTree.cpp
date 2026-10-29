#include "BST.h"

void BST::clearTree(Node*& node) {
    if (!node) return;
    clearTree(node->left);
    clearTree(node->right);
    delete node;
    node = nullptr;
}

void BST::clearTree() { clearTree(root); }
