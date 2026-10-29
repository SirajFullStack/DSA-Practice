#include "BST.h"

int BST::find_Predecessor(int val) {
    if (!root) {
        cout << "Tree have no child so no Predecessor in this time.\n";
        return -1;
    }

    Node* temp = root;
    while (temp && temp->data != val) {
        if (temp->data > val)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if (!temp) {
        cout << "This type have no value in this tree.\n";
        return -1;
    }

    if (temp->left) {
        temp = temp->left;
        while (temp->right)
            temp = temp->right;
        return temp->data;
    } else {
        Node* current = root;
        Node* pre = nullptr;

        while (current->data != val) {
            if (current->data > val) {
                current = current->left;
            } else {
                pre = current;
                current = current->right;
            }
        }

        if (!pre) {
            cout << "No Predecessor of " << val << " because it is the lowest node.\n";
            return -1;
        }
        return pre->data;
    }
}

void BST::find_Predecessor() {
    int v;
    cout << "Enter value for Predecessor: ";
    cin >> v;
    int x = find_Predecessor(v);
    if (x != -1)
        cout << "Predecessor of " << v << " is " << x << endl;
}
