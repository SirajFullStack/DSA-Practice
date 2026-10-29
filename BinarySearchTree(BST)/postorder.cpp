#include "BST.h"

void BST::PostOrder(Node* node) {
    if (!node) return;
    PostOrder(node->left);
    PostOrder(node->right);
    cout << node->data << " ";
}

void BST::PostOrder() {
    if (!root) cout << "\nTree have no child yet.\n";
    PostOrder(root);
}
