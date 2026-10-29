#include "BST.h"

void BST::push_arr1(int v) { arr1[++top1] = v; }
void BST::push_arr2(int v) { arr2[++top2] = v; }
void BST::pop_arr1() { top1--; }
void BST::pop_arr2() { top2--; }

void BST::inorderToArr1(Node* node) {
    if (!node) return;
    inorderToArr1(node->left);
    push_arr1(node->data);
    inorderToArr1(node->right);
}

void BST::Distance() {
    delete[] arr2;
    arr2 = new int[top1];
    top2 = -1;

    for (int i = 1; i <= top1; i++) {
        if (arr1[i] > arr1[i - 1])
            push_arr2(arr1[i] - arr1[i - 1]);
        else
            push_arr2(arr1[i - 1] - arr1[i]);
    }
}

int BST::Min_dis(Node* node) {
    int n = countNodes(node);
    delete[] arr1;
    arr1 = new int[n];
    top1 = -1;

    inorderToArr1(node);
    Distance();

    int smallestGap = arr2[0];
    for (int i = 1; i <= top2; i++)
        if (arr2[i] < smallestGap)
            smallestGap = arr2[i];
    return smallestGap;
}

int BST::Min_dis() {
    if (!root || (!root->left && !root->right)) {
        cout << "we can't find distance because not possible of this node.\n";
        return -1;
    }
    return Min_dis(root);
}
