#include "BST.h"

int BST::max(Node* node) {
    if (!node) return -1;
    Node* temp = node;
    while (temp->right)
        temp = temp->right;
    return temp->data;
}

int BST::max() { return max(root); }
