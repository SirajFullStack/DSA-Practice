#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;

    //constrcuctor
    Node(int v){
        data=v;
        left=right=NULL;
    }
};

//BST class
class BST{
    Node* root; 
    int *arr1, *arr2, *arr;
    int top1, top2, top;

    //=================================== Private Body ==============================================

    //----------------- insertion --------------------
    Node* insert(Node *node, int v){
        if(!node) return new Node(v);

        if(node->data<v)
            node->right=insert(node->right,v);
        else if(node->data>v)
            node->left=insert(node->left,v);
        else 
            cout<<"Duplicate values is not allowed.\n";

        return node;
    }

    //------------ searching ---------------
    bool search(Node *node, int target){
        if(!node)return false;
        if(node->data==target) return true;
        if(node->data<target)
        return search(node->left,target);
        else
        return search(node->right,target);
    }


    //------------- deletion ---------------
    Node *deletion(Node *node, int v){
        if(!node) return NULL;

        if(node->data>v)
            node->left=deletion(node->left,v);
        else if(node->data<v)
            node->right=deletion(node->right,v);
        else{
            if(!node->left && !node->right){
                delete node;
                return NULL;                       // fixed: was "return node"
            }else if(!node->left){
                Node *del=node;
                node=node->right;
                delete del;
                return node;
            }else if(!node->right){
                Node *del=node;
                node=node->left;
                delete del;
                return node;
            }else{
                Node *parent=node;
                Node *child=node->left;            // fixed: was root->left

                while(child->right){
                    parent=child;
                    child=child->right;
                }
                
                if(parent==node){
                    child->right=node->right;
                    delete node;
                    return child;
                }else{
                    parent->right=child->left;     // fixed: was child->right
                    child->left=node->left;
                    child->right=node->right;
                    delete node;
                    return child;
                }
            }
        }

        return node;
    }

    //----------------- Clear tree -----------------
    void clearTree(Node *&node){
        if(!node) return;
        clearTree(node->left);
        clearTree(node->right);
        delete node;
        node=NULL;
    }

    //---------------------Traversal Methods ------------------
    //-------------------- PreOrder Methods  ------------------
    void PreOrder(Node *node){
        if(!node) return;
        cout<<node->data<<" ";
        PreOrder(node->left);
        PreOrder(node->right);
    }

    //-------------------- InOrder Methods  ------------------
    void InOrder(Node *node){
        if(!node) return;
       
        InOrder(node->left);
        cout<<node->data<<" ";
        InOrder(node->right);
    }

    //-------------------- PostOrder Methods  ------------------
    void PostOrder(Node *node){
        if(!node) return;
        
        PostOrder(node->left);
        PostOrder(node->right);
        cout<<node->data<<" ";
    }


    // ---------------- Total Height ---------------------------
    int Height(Node *node){
        if(!node) return -1;
        int lh=Height(node->left);
        int rh=Height(node->right);

        if(lh>rh)
            return lh+1;
        else
            return rh+1;
    }


    //------------------ Maximum node ---------------------
    int max(Node *node){
        if(!node) return -1;
        Node *temp=node;
        while(temp->right)
            temp=temp->right;

        return temp->data;
    }


    //------------------ Minimum node ----------------------
    int min(Node *node){
        if(!node) return -1;
        Node *temp=node;
        while(temp->left)
            temp=temp->left;

        return temp->data;
    }


    //-------------------- Total Nodes ----------------------
    int countNodes(Node *node){
        if(!node) return 0;
        return 1+countNodes(node->left)+countNodes(node->right);
    }


    //-------------------- Total Leaf ------------------------
    void count_leaf(Node *node,int &count){
        if(!node) return;
        if(!node->left && !node->right)
            count++;

        count_leaf(node->left,count);
        count_leaf(node->right,count);
    }


    //------------------- Inorder Successor ------------------
    int find_successor(int val){
        if(!root){
            cout<<"Tree have no child so no successor in this time.\n";
            return -1;
        }

        Node *temp=root;
        while(temp && temp->data!=val){
            if(temp->data>val)
                temp=temp->left;
            else if(temp->data<val)
                temp=temp->right;
            else
                break;
        }

        if(!temp){
            cout<<"This type have no value in this tree.\n";
            return -1;
        }

        if(temp->right){
            temp=temp->right;
            while(temp->left)
                temp=temp->left;
            return temp->data;
        }else{
            Node *current=root;
            Node *suc=NULL;

            while(current->data!=val){
                if(current->data>val){
                    suc=current;
                    current=current->left;
                }
                else if(current->data<val){
                    current=current->right;
                }
            }

            if(!suc && val>root->data){
                cout<<"This node have no successor because this is highest node.\n";
                return -1;
            }else if(!suc && val==root->data){
                cout<<"No successor of "<<val<<" because it is the highest node.\n";
                return -1;
            }
            else {
                return suc->data;
            }
        }
        return -1;
    }


    //----------------------- Inorder Predecessor -------------------------
    int find_Predecessor(int val){
        if(!root){
            cout<<"Tree have no child so no Predecessor in this time.\n";
            return -1;
        }

        Node *temp=root;
        while(temp && temp->data!=val){
            if(temp->data>val)
                temp=temp->left;
            else if(temp->data<val)
                temp=temp->right;
            else
                break;
        }

        if(!temp){
            cout<<"This type have no value in this tree.\n";
            return -1;
        }

        if(temp->left){
            temp=temp->left;
            while(temp->right)
                temp=temp->right;
            return temp->data;
        }else{
            Node *current=root;
            Node *pre=NULL;                        

            while(current->data!=val){
                if(current->data>val){
                    current=current->left;
                }
                else if(current->data<val){
                    pre=current;
                    current=current->right;
                }
            }

            if(!pre && val<root->data){
                cout<<"This node have no Predecessor because this is lowest node.\n";
                return -1;
            }else if(!pre && val==root->data){
                cout<<"No Predecessor of "<<val<<" because it is the lowest node.\n";
                return -1;
            }
            else {
                return pre->data;
            }
        }
        return -1;
    }


    //---------------------- Minimum Distance -----------------------------
    //push arr1
    void push_arr1(int v){
        arr1[++top1]=v;
    }

    //push arr2
    void push_arr2(int v){
        arr2[++top2]=v;
    }

    //pop arr1
    void pop_arr1(){
        top1--;
    }

    //pop arr2
    void pop_arr2(){
        top2--;
    }

    //push elements of tree based inorder method into arr1
    void inorderToArr1(Node *node){
        if(!node) return;

        inorderToArr1(node->left);
        push_arr1(node->data);
        inorderToArr1(node->right);
    }

    void Distance(){
        delete []arr2;
        arr2=new int[top1];
        top2=-1;

        for(int i=1; i<=top1; i++){
            if(arr1[i]>arr1[i-1])
                push_arr2(arr1[i]-arr1[i-1]);
            else
                push_arr2(arr1[i-1]-arr1[i]);
        }
    }

    int Min_dis(Node *node){
        int n=countNodes(node);
        delete []arr1;
        arr1=new int[n];
        top1=-1;
        
        inorderToArr1(node);
        Distance();
        int smallestGap=arr2[0];
        for(int i=1; i<=top2; i++){
            if(arr2[i]<smallestGap)
                smallestGap=arr2[i];
        }
        return smallestGap;
    }


    //----------------------- Maximum distance ----------------------------
    int Max_dis(Node *node){
        Node *mn=node;
        while(mn->left)
            mn=mn->left;            // smallest value

        Node *mx=node;
        while(mx->right)
            mx=mx->right;           // largest value

        return mx->data - mn->data;
    }


    //------------------------- Kth smallest sum --------------------------
    //push values
    void push(int v){
        arr[++top]=v;
    }

    //pop value
    void pop(){
        top--;                      
    }

    //push elements of tree based inorder method into arr
    void inorderToArr(Node *node){
        if(!node) return;

        inorderToArr(node->left);
        push(node->data);
        inorderToArr(node->right);
    }

    //find sum of kth smallest numbers
    int kth_smallest_sum(int k){
        int sum=0;
        for(int i=0; i<k; i++)
            sum+=arr[i];            
        return sum;
    }


    //----------------------- Kth largest sum -----------------------------
    int kth_Largest_sum(int k){
        int sum=0;
        while(k){
            sum+=arr[top];          
            pop();
            k--;
        }
        return sum;
    }

    
    //======================== Public Body =================================
    public:
    BST(){
        root=NULL;
        arr1=NULL;
        arr2=NULL;
        arr=NULL;                   
        top1=top2=top=-1;
    }
    ~BST(){
        delete[] arr1;
        delete[] arr2;
        delete[] arr;               
        clearTree(root);
    }
    void insert(int v){
        root=insert(root,v);
        cout<<"Insertion Successful.\n";
    }
    bool search(int v){ return search(root,v);}
    void deletion(int v){
        root=deletion(root,v);     
        cout<<"\nDeletion Successful";
    }
    void clearTree(){clearTree(root);}
    void PreOrder(){ 
        if(!root){
            cout<<"\nTree have no child yet.\n";}
        PreOrder(root);}
    void InOrder(){
        if(!root){
            cout<<"\nTree have no child yet.\n";}
        InOrder(root);}
    void PostOrder(){
        if(!root){
            cout<<"\nTree have no child yet.\n";}
        PostOrder(root);}
    int Height(){ return Height(root);}
    int max(){ return max(root);}
    int min(){ return min(root);}
    int countNodes(){ return countNodes(root);}
    int count_leaf(){
        int count=0;
        count_leaf(root,count);
        return count;
    }
    void find_successor(){
        int v;
        cout<<"Enter value for Successor: ";
        cin>>v;
        int x=find_successor(v);
        if(x!=-1){
            cout<<"Successor of "<<v<<" is "<<x<<endl;
        }
    }

    void find_Predecessor(){
        int v;
        cout<<"Enter value for Predecessor: ";
        cin>>v;
        int x=find_Predecessor(v);
        if(x!=-1){
            cout<<"Predecessor of "<<v<<" is "<<x<<endl;
        }
    }
    int Min_dis(){ 
        if(!root || (!root->left && !root->right)){
            cout<<"we can't find distance because not possible of this node.\n";
            return -1;
        }
        
        return Min_dis(root);
    }
    int Max_dis(){ 
        if(!root || (!root->left && !root->right)){
            cout<<"we can't find distance because not possible of this node.\n";
            return -1;
        }
        
        return Max_dis(root);
    }
    int kth_smallest_sum(){
        int n=countNodes(root);
        delete []arr;               // fixed: was arr_small
        arr=new int[n];
        top=-1;
        inorderToArr(root);

        int k;
        cout<<"Enter kth number: ";
        cin>>k;
        if(k<=0 || k>n){
            cout<<"Invalid input.!!!\n";
            return -1;
        }
        return kth_smallest_sum(k);
    }
    int kth_Largest_sum(){
        int n=countNodes(root);
        delete []arr;               // fixed: was arr_larg
        arr=new int[n];
        top=-1;
        inorderToArr(root);

        int k;
        cout<<"Enter kth number: ";
        cin>>k;
        if(k<=0 || k>n){
            cout<<"Invalid input.!!!\n";
            return -1;
        }
        return kth_Largest_sum(k);
    }
};



// =================================== Main ========================================================

int main(){
    BST tree;
    int ch, val, x;
    while(true){
        cout<<"\n\n================= Menu ==================\n";
        cout<<" 1-  Insert node\n 2-  Search value\n 3-  Delete node\n 4-  ClearTree\n 5-  Traversal\n 6-  Height\n 7-  Maximum value\n 8-  Minimum value\n 9-  Total Nodes\n 10- Total leaf Node\n 11- Inorder Successor\n 12- Inorder Predecessor\n 13- Minimum Distance between two nodes\n 14- Maximum distance between two nodes\n 15- Kth smallest sum\n 16- Kth largest sum\n 0-  Exit\n";
        cout<<"Enter choice: ";
        cin>>ch;

        switch(ch){
            case 1:
                cout<<"Enter value: ";
                cin>>val;
                if(val<0) continue;
                tree.insert(val);
                break;
            
            case 2:
                cout<<"Enter search value: ";
                cin>>val;
                if(tree.search(val))
                    cout<<"Value Found Out.\n";
                else
                    cout<<"Value Not Found Out.\n";
                break;

            case 3:
                cout<<"Enter delete value: ";
                cin>>val;
                if(tree.search(val))
                    tree.deletion(val);
                else
                    cout<<"This Type value not Present in Tree.\n";
                break;

            case 4:
                tree.clearTree();
                cout<<"Now, Tree is empty.\n";
                break;

            case 5:
                cout<<" 1- PreOrder Method\n 2- InOrder Method\n 3- PostOrder\n";
                cout<<"Which type of print do you want to do? ";
                cin>>ch;
                if(ch==1)
                    tree.PreOrder();
                else if(ch==2)
                    tree.InOrder();
                else if(ch==3)
                    tree.PostOrder();
                else
                    cout<<"Invalid choice.\n";
                break;

            case 6:
                cout<<"Total Height of tree is "<<tree.Height()<<endl;
                break;
    
            case 7:
                cout<<"Maximum value in node is "<<tree.max()<<endl;
                break;

            case 8:
                cout<<"Minimum value in node is "<<tree.min()<<endl;
                break;

            case 9:
                cout<<"Total Nodes in Tree are "<<tree.countNodes()<<endl;
                break;

            case 10:
                cout<<"Total Leaf Nodes are "<<tree.count_leaf()<<endl;
                break;

            case 11:
                tree.find_successor();
                break;

            case 12:
                tree.find_Predecessor();
                break;

            case 13:
                x=tree.Min_dis();
                if(x!=-1)
                    cout<<"Minimum Distance between two nodes is "<<x<<endl;
                break;

            case 14:
                x=tree.Max_dis();
                if(x!=-1)
                    cout<<"Maximum Distance between two node is "<<x<<endl;
                break;

            case 15:
                x=tree.kth_smallest_sum();
                if(x!=-1)
                    cout<<"Sum of kth smallest nodes is "<<x<<endl;
                break;

            case 16:
                x=tree.kth_Largest_sum();
                if(x!=-1)
                    cout<<"Sum of kth largest nodes is "<<x<<endl;
                break;

            case 0:                                    // fixed: this label was missing
                cout<<"\n===============================\n";
                cout<<"Thank you for using our menu.\n";
                cout<<"===============================\n";
                return 0;

            default:
                cout<<"Invalid choice.\n";
                cout<<"Try again.\n";
        }
    }
}
