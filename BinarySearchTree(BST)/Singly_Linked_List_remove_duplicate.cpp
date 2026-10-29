#include<iostream>
using namespace std;

class Node{
public:
int data;
Node *next;
Node(int v){
        data=v;
        next=NULL;
    }

};

class SLL{
Node *head, *tail;

    //array into linked list (add at tail)
void Array_LL(int *arr, int size, int i=0){
if(i==size)return;

Node *nN=new Node(arr[i]);
if(!head){
          head=tail=nN;
        }else{
            tail->next=nN;
            tail=nN;
        }
Array_LL(arr,size,i+1);
    }

void print_inorder(Node *temp){
if(!temp)return;
        cout<<temp->data<<" ";
print_inorder(temp->next);

    }

void print_in_reverseorder(Node *temp){
if(!temp)return;
print_in_reverseorder(temp->next);
        cout<<temp->data<<" ";
    }

    //remove all nodes after prev whose value is same as val
    //prev = node before temp , so it can be joined with next node
void remove_dublicate(Node *prev, Node *temp, int val){
if(!temp)return;

if(temp->data==val){
Node *nxt=temp->next;
            prev->next=nxt;
if(temp==tail) tail=prev;
delete temp;
remove_dublicate(prev,nxt,val);
        }else{
remove_dublicate(temp,temp->next,val);
        }
    }

void remove_adjacent(Node *temp){
if(!temp)return;
remove_dublicate(temp,temp->next,temp->data);
remove_adjacent(temp->next);
    }

    //delete all nodes
void clearList(){
while(head){
Node *del=head;
            head=head->next;
delete del;
        }
        tail=NULL;
    }

//================================= Public ====================================
public:
SLL():head(NULL),tail(NULL){}
~SLL(){
clearList();
    }
void conversion(int *arr,int size){
clearList();
Array_LL(arr,size);
    }
    // print all node
void print(){
if(!head){
            cout<<"List is empty.\n";return;
        }
print_inorder(head);
        cout<<endl;
    }
void print_reverse(){
if(!head){
            cout<<"List is empty.\n";return;
        }
print_in_reverseorder(head);
        cout<<endl;
    }
    //remove same value nodes (keep first one)
void remove_adjacent(){
remove_adjacent(head);
    }
};

int main(){
int arr[]={1,2,1,3,2,4,4};
int size=sizeof(arr)/sizeof(arr[0]);

SLL s1;
    s1.conversion(arr,size);
    cout<<"Before: ";
    s1.print();

    s1.remove_adjacent();
    cout<<"After: ";
    s1.print();
    cout<<"Reverse: ";
    s1.print_reverse();

return 0;
}
