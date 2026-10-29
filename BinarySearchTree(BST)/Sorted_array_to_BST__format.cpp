#include<iostream>
using namespace std;
int s=0;
class Node{
public:
int data;
Node *left, *right;
Node(int v){
        data=v;
        left=right=NULL;
    }
};

//BST class
class BST{
Node *root;

    //free all dynamic data
void deleteTree(Node *node){
if(!node) return;
deleteTree(node->left);
deleteTree(node->right);
delete node;
    }

    //sorted array from left side
Node *from_leftBST(Node *node, int *arr, int i){
if(i<0) return NULL;
if(!node) node=new Node(arr[i]);
        node->left=from_leftBST(node->left,arr,i-1);

return node;
    }

void Inorder(Node *root){
if(!root) return;

Inorder(root->left);
    cout<<root->data<<" ";
Inorder(root->right);
}

    //sorted array from right side
Node *from_rightBST(Node *node, int *arr, int i){
if(i>=s) return NULL;
if(!node) node=new Node(arr[i]);
        node->right=from_rightBST(node->right,arr,i+1);

return node;
    }

public:
BST():root(NULL){}
~BST(){deleteTree(root);}
void SortedArr_into_BST(int *arr,int size){
if(size<=0){
            cout<<"Array is empty.\n";
return;
        }
int mid=size/2;
        root=new Node(arr[mid]);
        root=from_leftBST(root,arr,mid);
        root=from_rightBST(root,arr,mid);
     }
void Inorder(){
if(!root){
            cout<<"Tree have no child yet.\n";
return;
        }
Inorder(root);
     }

};

int main(){
BST bst;
int arr[]={11,12,14,15,16,17,18,20,45,50,55,60};
    s=sizeof(arr)/sizeof(arr[0]);
    bst.SortedArr_into_BST(arr,s);
    bst.Inorder();
return 0;
}
