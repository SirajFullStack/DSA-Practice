#include "BST.h"

int BST::countNodes(Node* node) {
    if (!node) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

int BST::countNodes() { return countNodes(root); }
