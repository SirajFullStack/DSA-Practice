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

    //return height of node and update longest path (dia) in one traversal
int Diameter(Node *node,int &dia){
if(!node) return 0;

int lh=Diameter(node->left,dia);
int rh=Diameter(node->right,dia);

        //path which pass from this node (in edges)
if(lh+rh>dia)
        dia=lh+rh;

if(lh>rh)
return 1+lh;
else
return 1+rh;
    }

public:
BST():root(NULL){}
void insert(int v){
        root=insert(root,v);
    }
~BST(){clearTree(root);}

    //diameter in edges (for nodes count add 1)
int Longest_path_Diameter(){
if(!root) return 0;
int dia=0;
Diameter(root,dia);
return dia;
    }

};
int main(){
BST bst;
int arr[]={20,16,50,45,60,55,12,17,11,14,15,18};
int size=sizeof(arr)/sizeof(arr[0]);
for(int i=0; i<size; i++)
    bst.insert(arr[i]);

    cout<<"Diameter (edges): "<<bst.Longest_path_Diameter()<<endl;
return 0;
}
