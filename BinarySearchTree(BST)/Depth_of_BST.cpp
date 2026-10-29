#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *left , *right;
		Node(int v){
			data=v;
			left=right=NULL;
		}
};

//BST class
class BST{
	Node *root;
	
	void insert(Node *node , int v){
		if(!node)return new Node(v);
		
		if(node->data>v)
		node->left=insert(node->left,v);
		else if(node->data<v)
		node->right=insert(node->right,v);
		else{
			cout<<"Duplicate value is not allowed.\n";
			return node;
		}
		return node;
	}
	
	//free to all values
	void clearTree(Node *node){
		if(!node)return;
		
		clearTree(node->left);
		clearTree(node->right);
		Node *del=node;
		delete del;
		node=NULL;

	}
	
	
	public:
		BST():root(NULL){
		}
		~BST(){
			clearTree();
		}
};
int main(){
	
	return 0;
}
