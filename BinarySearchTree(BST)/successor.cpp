#include "BST.h"

int BST::find_successor(int val) {
    if (!root) {
        cout << "Tree have no child so no successor in this time.\n";
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

    if (temp->right) {
        temp = temp->right;
        while (temp->left)
            temp = temp->left;
        return temp->data;
    } else {
        Node* current = root;
        Node* suc = nullptr;

        while (current->data != val) {
            if (current->data > val) {
                suc = current;
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (!suc) {
            cout << "No successor of " << val << " because it is the highest node.\n";
            return -1;
        }
        return suc->data;
    }
}

void BST::find_successor() {
    int v;
    cout << "Enter value for Successor: ";
    cin >> v;
    int x = find_successor(v);
    if (x != -1)
        cout << "Successor of " << v << " is " << x << endl;
}
