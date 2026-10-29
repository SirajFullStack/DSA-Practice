#include "BST.h"

int main() {
    BST tree;
    int ch, val, x;
    while (true) {
        cout << "\n\n================= Menu ==================\n";
        cout << " 1-  Insert node\n 2-  Search value\n 3-  Delete node\n 4-  ClearTree\n 5-  Traversal\n 6-  Height\n 7-  Maximum value\n 8-  Minimum value\n 9-  Total Nodes\n 10- Total leaf Node\n 11- Inorder Successor\n 12- Inorder Predecessor\n 13- Minimum Distance between two nodes\n 14- Maximum distance between two nodes\n 15- Kth smallest sum\n 16- Kth largest sum\n 0-  Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                if (val < 0) continue;
                tree.insert(val);
                break;

            case 2:
                cout << "Enter search value: ";
                cin >> val;
                if (tree.search(val))
                    cout << "Value Found Out.\n";
                else
                    cout << "Value Not Found Out.\n";
                break;

            case 3:
                cout << "Enter delete value: ";
                cin >> val;
                if (tree.search(val))
                    tree.deletion(val);
                else
                    cout << "This Type value not Present in Tree.\n";
                break;

            case 4:
                tree.clearTree();
                cout << "Now, Tree is empty.\n";
                break;

            case 5:
                cout << " 1- PreOrder Method\n 2- InOrder Method\n 3- PostOrder\n";
                cout << "Which type of print do you want to do? ";
                cin >> ch;
                if (ch == 1) tree.PreOrder();
                else if (ch == 2) tree.InOrder();
                else if (ch == 3) tree.PostOrder();
                else cout << "Invalid choice.\n";
                break;

            case 6:  cout << "Total Height of tree is " << tree.Height() << endl; break;
            case 7:  cout << "Maximum value in node is " << tree.max() << endl; break;
            case 8:  cout << "Minimum value in node is " << tree.min() << endl; break;
            case 9:  cout << "Total Nodes in Tree are " << tree.countNodes() << endl; break;
            case 10: cout << "Total Leaf Nodes are " << tree.count_leaf() << endl; break;
            case 11: tree.find_successor(); break;
            case 12: tree.find_Predecessor(); break;

            case 13:
                x = tree.Min_dis();
                if (x != -1) cout << "Minimum Distance between two nodes is " << x << endl;
                break;

            case 14:
                x = tree.Max_dis();
                if (x != -1) cout << "Maximum Distance between two node is " << x << endl;
                break;

            case 15:
                x = tree.kth_smallest_sum();
                if (x != -1) cout << "Sum of kth smallest nodes is " << x << endl;
                break;

            case 16:
                x = tree.kth_Largest_sum();
                if (x != -1) cout << "Sum of kth largest nodes is " << x << endl;
                break;

            case 0:
                cout << "\n===============================\n";
                cout << "Thank you for using our menu.\n";
                cout << "===============================\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
                cout << "Try again.\n";
        }
    }
}
