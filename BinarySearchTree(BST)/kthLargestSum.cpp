#include "BST.h"

int BST::kth_Largest_sum(int k) {
    int sum = 0;
    while (k) {
        sum += arr[top];
        pop();
        k--;
    }
    return sum;
}

int BST::kth_Largest_sum() {
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
    return kth_Largest_sum(k);
}
