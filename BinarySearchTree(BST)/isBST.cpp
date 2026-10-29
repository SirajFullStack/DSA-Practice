#include<iostream>
using namespace std;

class Node{
   public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
}; 

class Solution{
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
	
	//check isBST
	   bool check(Node* root, long long low, long long high){ // value of low and high predefined 
       if (!root)
           return true;

       if(root->data <= low || root->data >= high)
           return false;

       return check(root->left, low, root->data) &&
              check(root->right, root->data, high);
   }

   bool isBST(Node* root){
       return check(root, LLONG_MIN, LLONG_MAX); //LLONG_MIN and LLONG_MAX defined
   }
    
  public:
  		Solution():root(NULL){}
		void insert(int v){
			if(v<0){
				cout<<"Negative value is not allowed.\n";return;
			}
			root=insert(root,v);
		}
     bool isBST(){
	 return isBST(root);}
};

int main(){
	int arr[]={20,16,50,45,60,12,11,17,18,15};
	int size=sizeof(arr)/sizeof(arr[0]);
	
    Solution bst;
	for(int i=0; i<size; i++)
	bst.insert(arr[i]);
	
	if(bst.isBST())
	cout<<"Yes.\n";
	else
	cout<<"No\n";
	
	return 0;
}
