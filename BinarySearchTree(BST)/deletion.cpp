#include "BST.h"

Node* BST::deletion(Node* node, int v) {
    if (!node) return nullptr;

    if (node->data > v)
        node->left = deletion(node->left, v);
    else if (node->data < v)
        node->right = deletion(node->right, v);
    else {
        if (!node->left && !node->right) {
            delete node;
            return nullptr;
        } else if (!node->left) {
            Node* del = node;
            node = node->right;
            delete del;
            return node;
        } else if (!node->right) {
            Node* del = node;
            node = node->left;
            delete del;
            return node;
        } else {
            Node* parent = node;
            Node* child = node->left;

            while (child->right) {
                parent = child;
                child = child->right;
            }

            if (parent == node) {
                child->right = node->right;
                delete node;
                return child;
            } else {
                parent->right = child->left;
                child->left = node->left;
                child->right = node->right;
                delete node;
                return child;
            }
        }
    }
    return node;
}

void BST::deletion(int v) {
    root = deletion(root, v);
    cout << "\nDeletion Successful";
}
