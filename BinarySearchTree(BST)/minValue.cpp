#include "BST.h"

int BST::min(Node* node) {
    if (!node) return -1;
    Node* temp = node;
    while (temp->left)
        temp = temp->left;
    return temp->data;
}

int BST::min() { return min(root); }
