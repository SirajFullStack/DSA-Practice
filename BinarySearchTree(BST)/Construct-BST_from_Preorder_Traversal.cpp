#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
	
	Node(int v){
		data=v;
		left=right=NULL;
	}
};

class BST{
	Node *root;
	
	//preorder traversal 
	void Preorder(Node *node){
        if(!node) return;
        cout<<node->data<<" ";
        Preorder(node->left);
        Preorder(node->right);
    }
    
    //insertion through preorder
    Node* insertion_preorder(Node *node ,int v){
			if(!node)return new Node(v);
			
			if(node->data<v)
			node->right=insertion_preorder(node->right,v);
			else if(node->data>v)
			node->left=insertion_preorder(node->left,v);
			
			return node;
		}
		
	public:
		BST():root(NULL){}
		void insertion_Preorder(int v){
			root=insertion_preorder(root,v);
		}
		void print(){
		
			if(!root)return;
			
			cout<<"PreOrder Traversal:  ";
			Preorder(root);
		}
};

int main(){
	int pre[]={40, 30, 35, 80, 100};
	int size=sizeof(pre)/sizeof(pre[0]);
	
	BST bst;
	for(int i=0; i<size; i++){
		bst.insertion_Preorder(pre[i]);
	}
	bst.print();
	
	return 0;
}
