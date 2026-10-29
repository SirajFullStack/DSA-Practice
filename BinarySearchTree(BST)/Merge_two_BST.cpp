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

    //inorder: BST into sorted doubly linked list
void convert_BST_into_DLL(Node2 *node){
if(!node) return;
convert_BST_into_DLL(node->left);
insertionDLL(node->data);
convert_BST_into_DLL(node->right);
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
    }

    //merge sorted doubly linked list of other BST into this one (dummy node concept)
void Merge_BST(BST &other){
if(!head && !other.head){
            cout<<"Convert both BST first.\n";return;
        }

Node1 dummy(0);
Node1 *t=&dummy;
Node1 *a=head;
Node1 *b=other.head;

while(a && b){
if(a->data<b->data){
            t->next=a;
            a->pre=t;
            t=a;
            a=a->next;
        }
else if(a->data>b->data){
            t->next=b;
            b->pre=t;
            t=b;
            b=b->next;
        }
else{
            //same value: keep one, delete other
            t->next=a;
            a->pre=t;
            t=a;
            a=a->next;
Node1 *del=b;
            b=b->next;
delete del;
        }
    }

if(a){
        t->next=a;
        a->pre=t;
    }
else if(b){
        t->next=b;
        b->pre=t;
    }

        head=dummy.next;
if(head) head->pre=NULL;

        tail=head;
while(tail && tail->next)
        tail=tail->next;

        //nodes now belong to this list
        other.head=other.tail=NULL;
        cout<<"Merged successfully.\n";
    }

    //print doubly linked list
void print(){
if(!head){
            cout<<"List is empty.\n";return;
        }
Node1 *temp=head;
while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};

int main(){
BST bst1, bst2;
int arr1[]={20,10,30,5,15};
int arr2[]={25,15,40,12,28};
int size1=sizeof(arr1)/sizeof(arr1[0]);
int size2=sizeof(arr2)/sizeof(arr2[0]);

for(int i=0; i<size1; i++)
    bst1.insertionBST(arr1[i]);
for(int i=0; i<size2; i++)
    bst2.insertionBST(arr2[i]);

    bst1.convert_BST_into_DLL();
    bst2.convert_BST_into_DLL();

    bst1.Merge_BST(bst2);
    bst1.print();
return 0;
}
