// Recursive function to generate the binary tree in the given shape.
// Odd value -> left child, even value -> right child; right child is created first.
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;

    //constructor
    Node(int v){
        data=v;
        left=right=NULL;
    }
};

class BST{
    Node* root;

    //clear all nodes of tree
    void clearTree(Node *&node){
        if(!node) return;

        clearTree(node->left);
        clearTree(node->right);

        delete node;
        node=NULL;
    }

    //print in-order (left -> root -> right)
    void inOrder(Node *node){
        if(!node) return;

        inOrder(node->left);
        cout<<node->data<<" ";
        inOrder(node->right);
    }

    //insert value (odd goes left, even goes right, right is filled first)
    Node *insert_BST(Node *node, int v){
        if(!node) return new Node(v);

        if(node->left && node->right){          // both children full: go down the right chain
            node->right=insert_BST(node->right,v);
        }
        else if(v%2!=0){                        // odd value: wants the left side
            if(!node->right)
                cout<<"Place not more. First create the right node then input "<<v<<".\n";
            else
                node->left=new Node(v);
        }
        else{                                   // even value: wants the right side
            if(!node->right)
                node->right=new Node(v);
            else
                node->right=insert_BST(node->right,v);
        }
        return node;
    }

public:
    BST(){
        root=NULL;
    }
    ~BST(){
        clearTree(root);
        root=NULL;
    }
    void insert_BST(int v){
        root=insert_BST(root,v);
    }
    void inOrder(){
        inOrder(root);
    }
};

int main(){
    BST tree;
    int arr[]={1,2,3,4,5,6,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<size; i++)
        tree.insert_BST(arr[i]);

    //print
    cout<<"\n----------------------- Inorder Traversal ----------------------\n";
    tree.inOrder();
    cout<<"\n----------------------------------------------------------------\n";

    return 0;
}
