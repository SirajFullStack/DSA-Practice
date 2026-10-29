#include<iostream>
using namespace std;

//node class (same node is used for BST and for doubly linked list)
//left = pre , right = next after conversion
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
Node *head, *prev;

    //clear to all nodes of tree
void clearTree(Node *node){
if(!node) return;

clearTree(node->left);
clearTree(node->right);

delete node;
}

    //clear to all nodes of doubly linked list (go by right pointer)
void clearDLL(){
while(head){
Node *temp=head;
            head=head->right;
delete temp;
        }
    }

    //insertion of BST
Node* insertionBST(Node *node,int v){
if(!node) return new Node(v);

if(node->data<v)
        node->right=insertionBST(node->right,v);
else if(node->data>v)
    node->left=insertionBST(node->left,v);
else
cout<<"Duplicate value is not allowed.\n";
return node;
    }

    //in-place converstion bst into doubly linked list (no new node)
void convert_BST_into_DLL(Node *node){
if(!node) return;

convert_BST_into_DLL(node->left);

if(!prev)
        head=node;
else{
        prev->right=node;
        node->left=prev;
    }
    prev=node;

convert_BST_into_DLL(node->right);
    }

public:
BST():root(NULL),head(NULL),prev(NULL){}
~BST(){
clearTree(root);
clearDLL();
    }
void insertionBST(int v){
if(head){
            cout<<"Tree is already converted into list.\n";return;
        }
if(v<0){
            cout<<"Negative value is not allowed.\n";return;
        }
       root=insertionBST(root,v);
    }
void convert_BST_into_DLL(){
if(!root){
            cout<<"BST have no child or already converted.\n"; return;
        }
convert_BST_into_DLL(root);
        root=NULL;
        cout<<"Conversion successfully.\n";
    }

    //print forward (by right pointer)
void print(){
if(!head){
            cout<<"Convert the BST first.\n";return;
        }
Node *temp=head;
while(temp){
            cout<<temp->data<<" ";
            temp=temp->right;
        }
        cout<<endl;
    }

    //print backward (by left pointer) to check pre links
void printReverse(){
if(!head){
            cout<<"Convert the BST first.\n";return;
        }
Node *temp=head;
while(temp->right)
        temp=temp->right;
while(temp){
            cout<<temp->data<<" ";
            temp=temp->left;
        }
        cout<<endl;
    }

};

int main(){
BST bst;
int arr[]={20,16,50,45,60,55,12,17,11,14,15,18};
int size=sizeof(arr)/sizeof(arr[0]);

for(int i=0; i<size; i++)
    bst.insertionBST(arr[i]);

    bst.convert_BST_into_DLL();
    cout<<"Forward: ";
    bst.print();
    cout<<"Backward: ";
    bst.printReverse();
return 0;
}
