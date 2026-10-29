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
	 int *arr;
	 int size, top;
	 
	 void push(int v){
        arr[++top]=v;
    }

    // insert value in tree
	Node *insert(Node *node, int v){
	if(!node) return new Node(v);
	if(v<node->data)
            node->left=insert(node->left, v);
			else if(v>node->data)
            node->right=insert(node->right, v);
			else
            cout<<"Duplicate value is not allowed.\n";
			return node;
    }
	
	int countNodes(Node *node){
	if(!node) return 0;
	return 1+countNodes(node->left)+countNodes(node->right);
    }

    // inorder traversal -> sorted values go into arr
	void inorder(Node *node){
	if(!node) return;
	inorder(node->left);
	push(node->data);
	inorder(node->right);
    }

    // free all tree nodes
	void deleteTree(Node *node){
	if(!node) return;
	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
    }
	
	void buildArray(){
	delete[] arr;
	size=countNodes(root);
	arr=new int[size];
	top=-1;
	inorder(root);
    }

    // k is 1-based position (k=1 is smallest)
	int find_kth(int i, int k){
	if(k==i) return arr[i];
	return find_kth(--i,k);
    }
	
	public:
	BST(){
        arr=NULL;
        root=NULL;
        top=-1;
        size=0;
    }
	
	~BST(){
	delete[] arr;
	deleteTree(root);
    }
	
	void insert(int val){
        root=insert(root, val);
    }
	
	void kth_smallest(){
	int k;
        cout<<"Enter kth position: ";
        cin>>k;
		buildArray();
		if(k<1 || k>size){
            cout<<"Position is less than 1 or more than size, not allowed.\n";return;
        }
        cout<<"Smallest value at position "<<k<<" is "<<find_kth(size-1,size-k)<<endl;
    }

};

int main(){
     BST bst;
	 int arr[]={20,16,50,45,60,55,12,17,11,14,15,18};
	 int size=sizeof(arr)/sizeof(arr[0]);
	 for(int i=0; i<size; i++)
    bst.insert(arr[i]);

    bst.kth_smallest();
	
	return 0;
}
