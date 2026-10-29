#include<iostream>
using namespace std;
class Node{
public:
int data;
Node *left, *right;

    //constructor
Node(int v){
        data=v;
        left=right=NULL;
    }
};

class BST{
    Node* root;

    //insert value 
	Node* insert(Node *root, int v){
	if(!root)
	return new Node(v);
	
	if(v>root->data)
	root->right=insert(root->right,v);
	else if(v<root->data)
	root->left=insert(root->left,v);
	else
	cout<<"Duplicate not allowed.\n";
	return root;
}

    //clear to all dynamic data
	void clearTree(Node *&node){
	if(!node) return;
	
	clearTree(node->left);
	clearTree(node->right);
	
	delete node;
    node=NULL;
}

    // search node
	bool search(Node *node, int key){
	if(!node) return false;               
	if(node->data==key) return true;   
	
	if(key<node->data)
	return search(node->left, key);
	else
	return search(node->right, key);
}

    //find lowest common ancestor
	int findLCA(Node *node, int l,int r){
	if(node->data>l && node->data>r)
	return findLCA(node->left,l,r);
	else if(node->data<l && node->data<r)
	return findLCA(node->right,l,r);
	
	return node->data;
       }
	   
	   public:
	   BST():root(NULL){}
	   void insert(int v){
	   root=insert(root,v);
    }
	~BST(){clearTree(root);}
	void LCA(){
	if(!root){
            cout<<"BST is empty.\n"; return;
        }
		int L,R;
        //take value for left 
        cout<<"Enter left value: ";
        cin>>L;
		if(!search(root,L)){
            cout<<"This type value not present in BST.\n";return;
        }

        //take input for right 
        cout<<"Enter right value: ";
        cin>>R;
		if(!search(root,R)){
            cout<<"This type value not present in BST.\n";return;
        }
		
		int Least=findLCA(root,L,R);
        cout<<"Least common ancestor of "<<L<<" and "<<R<<" is "<<Least<<endl;
    }


};
int main(){
     BST bst;
	 int arr[]={20,16,50,45,60,55,12,17,11,14,15,18};
	 int size=sizeof(arr)/sizeof(arr[0]);
	 for(int i=0; i<size; i++)
	 bst.insert(arr[i]);

    bst.LCA();
	
	return 0;
}
