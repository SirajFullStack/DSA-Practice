#include<iostream>
using namespace std;

//node class for doubly linked list
class Node1{
public:
int data;
Node1 *next, *pre;
Node1(int v){
        data=v;
        next=pre=NULL;
    }
};

//node class for BST
class Node2{
public:
int data;
Node2 *left, *right;
Node2(int v){
        data=v;
        left=right=NULL;
    }
};

//BST class
class BST{
Node2 *root;
Node1 *head, *tail;

    //clear to all nodes of tree
void clearTree(Node2 *&node){
if(!node) return;

clearTree(node->left);
clearTree(node->right);

delete node;
    node=NULL;
}

    //clear to all nodes of doubly linked list
void clearDLL(){
while(head){
Node1 *temp=head;
            head=head->next;
delete temp;
        }
        tail=NULL;
    }

    //insertion of BST
Node2* insertionBST(Node2 *node,int v){
if(!node) return new Node2(v);

if(node->data<v)
        node->right=insertionBST(node->right,v);
else if(node->data>v)
    node->left=insertionBST(node->left,v);
else
cout<<"Duplicate value is not allowed.\n";

return node;
    }

    //insertion of doubly linked list
void insertionDLL(int v){
Node1 *nN=new Node1(v);
if(!head){
            head=tail=nN;
return;
        }

        nN->pre=tail;
        tail->next=nN;
        tail=nN;

    }

void convert_BST_into_DLL(Node2 *node){
if(!node) return;
convert_BST_into_DLL(node->left);
insertionDLL(node->data);
convert_BST_into_DLL(node->right);
    }

    //print doubly linked list
void Print(){
if(!head){
            cout<<"Convert the BST first.\n";return;
        }
Node1 *temp=head;
while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

public:
BST():root(NULL),head(NULL),tail(NULL){}
~BST(){
clearTree(root);
clearDLL();
    }
void insertionBST(int v){
if(v<0){
            cout<<"Negative value is not allowed.\n";return;
        }
       root=insertionBST(root,v);
    }
void convert_BST_into_DLL(){
if(!root){
            cout<<"BST have no child so conversion not possible.\n"; return;
        }
clearDLL();
convert_BST_into_DLL(root);
        cout<<"Conversion successfully.\n";
    }
void print(){
Print();
    }

};

int main(){
BST bst;
int arr[]={20,16,50,45,60,55,12,17,11,14,15,18};
int size=sizeof(arr)/sizeof(arr[0]);

for(int i=0; i<size; i++)
    bst.insertionBST(arr[i]);

    bst.convert_BST_into_DLL();
    bst.print();
return 0;
}
