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

    //insert value 
Node* insert(Node *root, int v){
if(!root)
return new Node(v);

if(v>root->data)
    root->right=insert(root->right,v);
else if(v<root->data)
    root->left=insert(root->left,v);
else
cout<<"Duplicate not allowed.\n";
return root;
}

    //clear to all dynamic data
void clearTree(Node *&node){
if(!node) return;

clearTree(node->left);
clearTree(node->right);

delete node;
    node=NULL;
}

      //search value
bool search(Node *root , int target){
while(root){
if(target<root->data)
        root=root->left;
else if(target>root->data)
    root=root->right;
else
return true;
    }
return false;
}

       //print in-order (left -> root -> Right)
void Inorder(Node *node){
if(!node) return;

Inorder(node->left);
    cout<<node->data<<" ";
Inorder(node->right);
}

    //swap values of two nodes (to make invalid BST)
void swapValues(Node *node,int n1,int n2){
if(!node) return;
if(node->data==n1) node->data=n2;
else if(node->data==n2) node->data=n1;
swapValues(node->left,n1,n2);
swapValues(node->right,n1,n2);
    }

    //in-order with prev pointer, find two wrong nodes (where ascending order break)
void findWrongNodes(Node *node,Node *&prev,Node *&first,Node *&second){
if(!node) return;

findWrongNodes(node->left,prev,first,second);

if(prev && prev->data>node->data){
if(!first) first=prev;
        second=node;
    }
    prev=node;

findWrongNodes(node->right,prev,first,second);
}

public:
BST():root(NULL){}
void insert(int v){
        root=insert(root,v);
    }
~BST(){
clearTree(root);
    }
void Inorder(){Inorder(root);}

    //swap two values by user to make invalid BST
void build_invalid_BST(){
if(!root){
            cout<<"BST is empty.\n";return;
        }
int n1,n2;
        cout<<"Enter swapped value (n1): ";
        cin>>n1;
if(!search(root,n1)){
            cout<<"This type value not present in BST.\n";return;
        }
        //take input for n2
        cout<<"Enter swapped value (n2): ";
        cin>>n2;
if(!search(root,n2)){
            cout<<"This type value not present in BST.\n";return;
        }
if(n1==n2){
            cout<<"n1 and n2 are both same value so BST remain valid.\n";return;
        }
        //set up for invalid BST
swapValues(root,n1,n2);
    }

    //recover BST
void Recover_BST(){
if(!root){
            cout<<"BST is empty.\n";return;
        }
Node *prev=NULL, *first=NULL, *second=NULL;
findWrongNodes(root,prev,first,second);

if(!first){
            cout<<"BST is already valid.\n";return;
        }

        //swap only data of two wrong nodes (structure same)
int x=first->data;
        first->data=second->data;
        second->data=x;
   }


};
int main(){
BST bst;
int arr[]={20,16,50,45,60,55,12,17,11,14,15,18};
int size=sizeof(arr)/sizeof(arr[0]);
for(int i=0; i<size; i++)
    bst.insert(arr[i]);

    cout<<"Valid BST: ";
    bst.Inorder();
    cout<<endl;

    bst.build_invalid_BST();
    cout<<"\nInvalid BST: ";
    bst.Inorder();
    cout<<endl;

    bst.Recover_BST();
    cout<<"After recovery of BST: ";
    bst.Inorder();
    cout<<endl;

return 0;
}
