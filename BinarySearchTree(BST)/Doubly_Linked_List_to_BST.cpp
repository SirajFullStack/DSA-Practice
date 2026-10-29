#include<iostream>
using namespace std;
class Node{
public:
int data;
Node *next;
Node *pre;

Node(int v):data(v), next(NULL) , pre(NULL){}


};

class DLL{
Node* head;
Node *root;

    // insert value in tree
Node *insert_bst(Node *node, int v){
if(!node) return new Node(v);
if(v<node->data)
            node->pre=insert_bst(node->pre, v);
else if(v>node->data)
            node->next=insert_bst(node->next, v);
else
            cout<<"Duplicate value is not allowed.\n";
return node;
    }

      //insertion of Doubly linked list
void insertion(int v){
Node* newNode=new Node(v);
if(!head){
            head=newNode;
return;
        }

        newNode->next=head;
        head->pre=newNode;
        head=newNode;

     }

     //print all values of doubly linked list
void print(Node *temp){
if(!temp) return;
print(temp->next);
         cout<<temp->data<<" ";
     }

     //print bst followed by inorder traversal 
void Inorder(Node *node){
if(!node) return;

Inorder(node->pre);
    cout<<node->data<<" ";
Inorder(node->next);
}

     //convert doubly linked list into bst
void dll_into_bst(Node *temp){
if(!temp)return;
        root=insert_bst(root,temp->data);
dll_into_bst(temp->next);
     }

     //clear all nodes of tree
void clearTree(Node *&node){
if(!node) return;

clearTree(node->pre);
clearTree(node->next);

delete node;
        node=NULL;
     }

     //clear all nodes of doubly linked list
void clearList(){
while(head){
Node *temp=head;
            head=head->next;
delete temp;
        }
     }

//====================== Public ====================================
public: 
DLL(): head(NULL),root(NULL){}
~DLL(){
clearTree(root);
clearList();
     }
void insert(int v){
if(v<0){
            cout<<"Negative value is not allowed.\n";return;
        }
insertion(v);
     }
void Print(){
if(!head){
            cout<<"Doubly linked list is empty.\n";return;
        }
print(head);
     }
void dll_into_bst(){
if(!head){
            cout<<"Doubly linked list is empty so conversion not possible.\n";return;
        }
        //remove old tree first, so no duplicate message on re-conversion
clearTree(root);
dll_into_bst(head);
     }
void print_bst(){
if(!root){
            cout<<"1st change to doubly linked list into BST.\n";return;
        } 
Inorder(root);
    }

};

int main(){
DLL dll;
int size, val;
    cout<<"Enter number of nodes: ";
    cin>>size;

    cout<<"Enter values of nodes: ";
for(int i=0; i<size; i++){
        cin>>val;
        dll.insert(val);
    }

    cout<<"Doubly linked list: ";
    dll.Print();
    cout<<endl;

    dll.dll_into_bst();
    cout<<"BST (inorder): ";
    dll.print_bst();
    cout<<endl;
return 0;
}
