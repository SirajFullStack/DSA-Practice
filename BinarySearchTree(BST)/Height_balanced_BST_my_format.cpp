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
int *arr;
int top;

    //clear to memory
void clearTree(Node *node){
if(!node) return;
clearTree(node->left);    
clearTree(node->right);     
delete node;                
    }

    //insert value 
Node* insert(Node *root, int v){
if(!root)
return new Node(v);

if(v>root->data)
    root->right=insert(root->right,v);
else if(v<root->data)
    root->left=insert(root->left,v);
else
cout<<"Duplicate not allowed";
return root;
}

int Height(Node *node){
if(!node){return 0;}
int lh=Height(node->left);
int rh=Height(node->right);

if(lh>rh)
return 1+lh;
else 
return 1+rh;
    }

    //check balance on every node
bool Height_Balanced_BST(Node *node){
if(!node) return true;

int l_height=Height(node->left);
int r_height=Height(node->right);
int diff;

if(l_height>r_height)
    diff=l_height-r_height;
else
    diff=r_height-l_height;

if(diff>1) return false;

return Height_Balanced_BST(node->left) && Height_Balanced_BST(node->right);
    }


public:
BST(){
        root=NULL;
        arr=NULL;
        top=-1;
    }


~BST(){
delete[] arr;
clearTree(root);
        root = NULL;
    }   
void insert(int v){
        root=insert(root,v);
    }
bool Height_Balanced_BST(){
return Height_Balanced_BST(root);
    }



};
int main(){
BST bst;
int arr[]={20,10,24,2,14,25,35};
int size=sizeof(arr)/sizeof(arr[0]);
for(int i=0; i<size; i++)
    bst.insert(arr[i]);

if(bst.Height_Balanced_BST())
    cout<<"Height Balanced BST\n";
else
cout<<"Not Height Balanced BST\n";

return 0;
}
