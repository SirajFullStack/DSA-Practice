#include "BST.h"

int BST::Max_dis(Node* node) {
    Node* mn = node;
    while (mn->left)
        mn = mn->left;      // smallest value

    Node* mx = node;
    while (mx->right)
        mx = mx->right;     // largest value

    return mx->data - mn->data;
}

int BST::Max_dis() {
    if (!root || (!root->left && !root->right)) {
        cout << "we can't find distance because not possible of this node.\n";
        return -1;
    }
    return Max_dis(root);
}
