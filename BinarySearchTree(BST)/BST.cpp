#include "BST.h"

BST::BST() {
    root = nullptr;
    arr1 = arr2 = arr = nullptr;
    top1 = top2 = top = -1;
}

BST::~BST() {
    delete[] arr1;
    delete[] arr2;
    delete[] arr;
    clearTree(root);
}
