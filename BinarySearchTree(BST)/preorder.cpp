#include "BST.h"

void BST::PreOrder(Node* node) {
    if (!node) return;
    cout << node->data << " ";
    PreOrder(node->left);
    PreOrder(node->right);
}

void BST::PreOrder() {
    if (!root) cout << "\nTree have no child yet.\n";
    PreOrder(root);
}
