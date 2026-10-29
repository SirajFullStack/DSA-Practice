#include "BST.h"

Node* BST::insert(Node* node, int v) {
    if (!node) return new Node(v);

    if (node->data < v)
        node->right = insert(node->right, v);
    else if (node->data > v)
        node->left = insert(node->left, v);
    else
        cout << "Duplicate values is not allowed.\n";

    return node;
}

void BST::insert(int v) {
    root = insert(root, v);
    cout << "Insertion Successful.\n";
}
