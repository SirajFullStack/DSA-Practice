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

     //find range between low and high , in the end return sum
void Range_and_sum(Node *node,int l , int h,int &sum){
if(!node) return;

if(node->data>l)
Range_and_sum(node->left,l,h,sum);

if(node->data>=l && node->data<=h){
         sum+=node->data;
       cout<<node->data<<" ";
    }

if(node->data<h)
Range_and_sum(node->right,l,h,sum);
}

public:
BST():root(NULL){}
void insert(int v){
        root=insert(root,v);
    }
~BST(){clearTree(root);}
void Range_and_sum(){
int l , h;
        cout<<"Enter low value: ";
        cin>>l;
        cout<<"Enter high value: ";
        cin>>h;

int sum=0;
        cout<<"Print: ";
Range_and_sum(root,l,h,sum);
        cout<<"\nTotal sum between "<<l<<" and "<<h<<" is "<<sum<<endl;

    }

};
int main(){
BST bst;
int arr[]={20,16,50,45,60,55,12,17,11,14,15,18};
int size=sizeof(arr)/sizeof(arr[0]);
for(int i=0; i<size; i++)
    bst.insert(arr[i]);

    bst.Range_and_sum();


return 0;
}
