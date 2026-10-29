#include "BST.h"

int BST::kth_smallest_sum(int k) {
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];
    return sum;
}

int BST::kth_smallest_sum() {
    int n = countNodes(root);
    delete[] arr;
    arr = new int[n > 0 ? n : 1];
    top = -1;
    inorderToArr(root);

    int k;
    cout << "Enter kth number: ";
    cin >> k;
    if (k <= 0 || k > n) {
        cout << "Invalid input.!!!\n";
        return -1;
    }
    return kth_smallest_sum(k);
}
