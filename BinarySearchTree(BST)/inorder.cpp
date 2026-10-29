#include "BST.h"

void BST::InOrder(Node* node) {
    if (!node) return;
    InOrder(node->left);
    cout << node->data << " ";
    InOrder(node->right);
}

void BST::InOrder() {
    if (!root) cout << "\nTree have no child yet.\n";
    InOrder(root);
}
