#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int v){
        data = v;
        left = right = NULL;
    }
};

class BST{
    int *root1, *root2;
    int s1, s2;
    Node *root;

    void push_stack1(int v){ root1[s1++] = v; }
    void push_stack2(int v){ root2[s2++] = v; }

    Node *insert(Node *node, int v){
        if(!node) return new Node(v);
        if(v < node->data)
            node->left = insert(node->left, v);
        else if(v > node->data)
            node->right = insert(node->right, v);
        else
            cout << "Duplicate value is not allowed.\n";
        return node;
    }

    int countNodes(Node *node){
        if(!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    void deleteTree(Node *node){
        if(!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    void setStack1(Node *node){
        if(!node) return;
        push_stack1(node->data);
        setStack1(node->left);
        setStack1(node->right);
    }

    void setStack2(Node *node){
        if(!node) return;
        push_stack2(node->data);
        setStack2(node->left);
        setStack2(node->right);
    }

public:
    BST(){
        root1 = root2 = NULL;
        root = NULL;
        s1 = s2 = 0;
    }

    ~BST(){
        delete[] root1;
        delete[] root2;
        deleteTree(root);
    }

    void insert(int v){
        root = insert(root, v);
    }

    
    int countpair(BST &other, int x){
        delete[] root1;
        delete[] root2;

        // fill stack1 with this tree's values
        int n1 = countNodes(root);
        root1 = new int[n1];
        s1 = 0;
        setStack1(root);

        // fill stack2 with the other tree's values
        int n2 = countNodes(other.root);
        root2 = new int[n2];
        s2 = 0;
        // setStack2 uses this object's s2/root2, so load from other.root
        setStack2(other.root);

        int count = 0;
        for(int i = 0; i < s1; i++){
            for(int j = 0; j < s2; j++){
                if(root1[i] + root2[j] == x)
                    count++;
            }
        }
        return count;
    }
};

int main(){
    BST bst1;
    int arr[] = {20,16,50,45,60,55,12};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < size; i++)
        bst1.insert(arr[i]);

    BST bst2;
    int arr1[] = {20,16,50,45,60,55,12,17,11,14,15,18};
    size = sizeof(arr1)/sizeof(arr1[0]);
    for(int i = 0; i < size; i++)
        bst2.insert(arr1[i]);

    int x;
    cout<<"enter: ";
    cin>>x;
    cout<<bst1.countpair(bst2, x)<<endl;
    return 0;
}
