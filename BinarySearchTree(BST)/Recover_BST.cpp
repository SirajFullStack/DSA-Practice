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

    //push value of stack
void push(int v){
        arr[++top]=v;
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

    //count nodes
int countNodes(Node *node){
if(!node) return 0;
return 1+countNodes(node->left)+countNodes(node->right);
    }

    //swap values of two nodes (to make invalid BST)
void swapValues(Node *node,int n1,int n2){
if(!node) return;
if(node->data==n1) node->data=n2;
else if(node->data==n2) node->data=n1;
swapValues(node->left,n1,n2);
swapValues(node->right,n1,n2);
    }

    //push in-order values of tree into stack
void push_inorder(Node *node){
if(!node) return;

push_inorder(node->left);
push(node->data);
push_inorder(node->right);
}

      //find two wrong positions in stack (where ascending order break)
void findWrongPositions(int i,int &first,int &second){
if(i>=top) return;
if(arr[i]>arr[i+1]){
if(first==-1) first=i;
        second=i+1;
    }
findWrongPositions(i+1,first,second);
}

      //fill sorted stack values back into tree by in-order (structure same)
void fillTree(Node *node,int &i){
if(!node) return;
fillTree(node->left,i);
        node->data=arr[i];
        i=i+1;
fillTree(node->right,i);
      }

public:
BST():root(NULL),arr(NULL),top(-1){}
void insert(int v){
        root=insert(root,v);
    }
~BST(){
clearTree(root);
delete []arr;
        arr=NULL;
        top=-1;
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
        //push invalid BST in stack
delete []arr;
        arr=new int[countNodes(root)];
        top=-1;
push_inorder(root);

        //find two wrong positions
int first=-1,second=-1;
findWrongPositions(0,first,second);
if(first==-1){
            cout<<"BST is already valid.\n";return;
        }

        //swap wrong values in stack
int x=arr[first];
        arr[first]=arr[second];
        arr[second]=x;

        //recovery of BST
int idx=0;
fillTree(root,idx);
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
