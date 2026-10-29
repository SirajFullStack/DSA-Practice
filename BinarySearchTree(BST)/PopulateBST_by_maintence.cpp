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
    Node *root, *pre;
    
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

  
  //helper()
   void helper(Node* node){
        if (!node) return;

        helper(node->right);     

        node->next=pre;      
        pre=node;

        helper(node->left);      
    }
    
    //populateNext
 void populateNext(Node* node){
        pre=NULL;
        helper(node);
    }
	
    public:
    	  Solution():root(NULL),pre(NULL){}
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
        if(!root) return;

        Node *curr=root;
        while(curr->left)          // sabse chhota node (leftmost)
            curr=curr->left;

        cout<<"Print Singly Linked List: ";
        while(curr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
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
