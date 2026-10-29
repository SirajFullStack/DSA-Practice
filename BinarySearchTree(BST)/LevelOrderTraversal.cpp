#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *left, *right;
		
		Node(int v){
			data=v;
			left=right=NULL;
		}
};

class BST{
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
	
	//find nodes
	int countNodes(Node *node){
		if(!node)return 0;
		return 1+countNodes(node->left)+countNodes(node->right);
	}
	
	//print to bst in levelOrder
	void levelOrder(Node *node){
		Node *queue[countNodes(node)];
		int front=0, rear=0;
		
		queue[rear++]=node;
		
		while(front<rear){
			Node *temp=queue[front++];
			cout<<temp->data<<" ";
			
			if(temp->left)
			queue[rear++]=temp->left;
			if(temp->right)
			queue[rear++]=temp->right;
		}
		
		
	}
	
	//=========================================== Public ====================================================
	public:
		BST():root(NULL){}
		void insert(int v){
			if(v<0){
				cout<<"Negative value is not allowed.\n";return;
			}
			root=insert(root,v);
		}
		void print_levelorder(){
			if(!root){
				cout<<"BST is empty.\n";
				return;
			}
			
			levelOrder(root);
		}
};

int main(){
	int arr[]={20,16,50,45,60,12,11,17,18,15};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	BST bst;
	for(int i=0; i<size; i++)
	bst.insert(arr[i]);
	
	cout<<"Level Order Traversal: ";
	bst.print_levelorder();
	
	return 0;
}
