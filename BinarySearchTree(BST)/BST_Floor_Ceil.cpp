#include<iostream>
using namespace std;
class Node{
public:
int data;
Node *left , *right;
    //constructor
Node(int v){
        data=v;
        left=right=NULL;
    }
};

//BST tree
class BST{
Node *root;
int *arr;
int size, top;

    //isempty
bool isempty(){return top==-1;}
    //push value into stack
void push(int v){
        arr[++top]=v;
    }

    //insert value in tree
Node *insert(Node *node, int v){
if(!node) return new Node(v);

if(v<node->data)
        node->left=insert(node->left,v);
else if(v>node->data)
    node->right=insert(node->right,v);
else
cout<<"dublicate value is not allowed.\n";

return node;
    }

    //count node
int countNodes(Node *node){
if(!node) return 0;
return 1+countNodes(node->left)+countNodes(node->right);
    }

    //push tree into array by inorder method
void inorder(Node *node){
if(!node) return;
inorder(node->left);
push(node->data);
inorder(node->right);
    }

    //delete all nodes of tree
void deleteTree(Node *node){
if(!node) return;
deleteTree(node->left);
deleteTree(node->right);
delete node;
    }

    //find floor by given value (largest value <= x)
int Floor(int i, int x, int ans){
if(i>top) return ans;
if(arr[i]>x) return ans;
return Floor(i+1,x,arr[i]);
    }

    //find ceil by given value (first value >= x)
int Ceil(int i, int x){
if(i>top) return -1;
if(arr[i]>=x) return arr[i];
return Ceil(i+1,x);
    }

    //build sorted array from tree
void buildArray(){
delete []arr;
        size=countNodes(root);
        arr=new int[size];
        top=-1;
inorder(root);
    }

//====================== public =====================================
public:
BST(){
        arr=NULL;
        root=NULL;
        top=-1;
        size=0;
    }
~BST(){
delete []arr;
deleteTree(root);
    }
void insert(){
int val;
        cout<<"Enter value of node: ";
        cin>>val;
if(val<0){
            cout<<"Negative value is not supported.\n";
return;
        }
        root=insert(root,val);
        cout<<"Value successfully added.\n";
    }

void Floor(){
int x;
        cout<<"Enter value: ";
        cin>>x;
if(x<0){
            cout<<"Negative value is not supported.\n";
return;
        }
        buildArray();
int res=Floor(0,x,-1);
if(res==-1)
        cout<<"Floor not found.\n";
else
    cout<<res<<" is Floor of "<<x<<endl;
    }

void Ceil(){
int x;
        cout<<"Enter value: ";
        cin>>x;
if(x<0){
            cout<<"Negative value is not supported.\n";
return;
        }
        buildArray();
int res=Ceil(0,x);
if(res==-1)
        cout<<"Ceil not found for this "<<x<<endl;
else
    cout<<res<<" is Ceil of "<<x<<endl;
    }

};
int main(){
BST bst;
int ch;
while(true){
        cout<<"\n 1- Insert value\n 2- Find Floor\n 3- Find Ceil\n 0- Exit\n";
        cin>>ch;

switch(ch){
case 1:
            bst.insert();
break;

case 2:
            bst.Floor();
break;

case 3:
            bst.Ceil();
break;

case 0:
            cout<<"Exiting.......\n";
return 0;

default:
            cout<<"Invalid choice......\n";
        }
    }


}
