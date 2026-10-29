#include "BST.h"

void BST::push(int v) { arr[++top] = v; }
void BST::pop() { top--; }

void BST::inorderToArr(Node* node) {
    if (!node) return;
    inorderToArr(node->left);
    push(node->data);
    inorderToArr(node->right);
}
