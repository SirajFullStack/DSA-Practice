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

class AVL{
	Node *root;
	
	//insertion of values
	Node *insert(Node *node , int v){
		if(!node) return new Node(v);
		
		
		if(node->data>v)
		node->left=insert(node->left,v);
		else if(node->data<v)
		node->right=insert(node->right,v);
		else
		cout<<"Duplicate value is not allowed.\n";
		
		return node;
	}
	
	//Traversal Preorder (do help for understand code is correct )
	void Preorder(Node *node){
		if(!node)return;
		cout<<node->data<<" ";
		Preorder(node->left);
		Preorder(node->right);
	}
	
	//calculate height
	int height(Node *node){
		if(!node)return 0;
		
		int lh=height(node->left);
		int rh=height(node->right);
		
		if(lh>rh)return lh+1;
		else return rh+1;
		
	}
	
	//calculate balance factor
	int BalanceFactor(Node *node){
		int lh=height(node->left);
		int rh=height(node->right);
		
		return lh-rh;
	}
	
	//left-left case 1 (apply the right rotation)
	Node *LL(Node *node, Node *node1){
		Node *temp=node1->right;      
		node1->right=node;
		node->left=temp;              
		return node1;
	}
	
	//Right-Right case 2 (apply the left rotation)
	Node *RR(Node *node, Node *node1){
		Node *temp=node1->left;       
		node1->left=node;
		node->right=temp;             
		return node1;
	}
	
	//Left-Right case 3 (apply the rotation based on order of letter)
	// 1st rotation apply left rotation , and then apply right rotation
	Node *LR(Node *node){
		node->left=RR(node->left,node->left->right);   
		return LL(node,node->left);                   
	}
	
	//Right-Left case 4 (apply the rotation based on order of letter)
	// 1st rotation apply right rotation , and then apply left rotation
	Node *RL(Node *node){
		node->right=LL(node->right,node->right->left); 
		return RR(node,node->right);                   
	}
	
	//************** actual AVL's implementation *******************
	Node *checkAVL(Node *node){
		if(!node) return NULL;
		
		node->left=checkAVL(node->left);     
		node->right=checkAVL(node->right);   
		int BF=BalanceFactor(node);
		if(BF>=2){
			if(BalanceFactor(node->left)>=0)
			node=LL(node,node->left);
			else
			node=LR(node);
		}else if(BF<=-2){
			if(BalanceFactor(node->right)<=0)
			node=RR(node,node->right);
			else
			node=RL(node);
		}
		return node;
	}
	//============================== PUBLIC =========================================
	public:
	AVL():root(NULL){}
	void insert(int v){
		if(v<=0){
			cout<<"Negative value is not allowed.\n";return;
		}
		
		root=insert(root,v);
		root=checkAVL(root);
	}
	void Preorder(){ 
		Preorder(root);
		cout<<endl;
	}
};

int main(){
	int arr[]={10,20,30,40,50,60};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	AVL avl;
	for(int i=0; i<size; i++)
	avl.insert(arr[i]);
	
	avl.Preorder();
	
	return 0;
}
