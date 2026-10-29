#include<iostream>
using namespace std;

class Node {
    public:
    int data;
     Node *left;
     Node *right;
     Node *next;

    Node(int x) {
        data=x;
        left=NULL;
        right=NULL;
        next=NULL;
    }
};

class Solution {
    Node *head, *tail;
    Node *root;
    
	Node *insert(Node *node, int v){
		if(!node)return new Node(v);
		
		if(node->data>v)
		node->left=insert(node->left,v);
		else if(node->data<v)
		node->right=insert(node->right,v);
		else{
			cout<<"Duplicate value is not allowed.\n"; return node;
		}
		return node;
	}

   //insert values
  void insertSLL(int v){
      Node *nN=new Node(v);
      if(!head){
          head=tail=nN;return;
      }
      tail->next=nN;
      tail=nN;
  }
    void populateNext(Node *root){
        if(!root)return;
        populateNext(root->left);
        insertSLL(root->data);
        populateNext(root->right);
    }
    
    //print singly linked list
     void print(Node *head){
	    	if(!head)return;
		 cout<<head->data<<" ";
		 
		 print(head->next);
	}
	
    public:
    	  Solution():head(NULL),tail(NULL){}
    void populateNext(){
    	populateNext(root);
	}
	void insert(int v){
		if(v<0){
			cout<<"Negative value is not allowed.\n";return;
		}
		root=insert(root,v);
	}
	void print(){
		if(!head) return;
		cout<<"Print Singly Linked  List: ";
		print(head);
		cout<<endl;
	}
	   
};

int main(){
	int arr[]={20,16,50,45,60,12,11,17,18,15};
	int size=sizeof(arr)/sizeof(arr[0]);
	
    Solution bst;
	for(int i=0; i<size; i++)
	bst.insert(arr[i]);
	
	bst.populateNext();
	bst.print();
	
	return 0;
}
