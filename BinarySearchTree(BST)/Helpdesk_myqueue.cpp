#include<iostream>
#include<string>
using namespace std;

//one student request
class Request{
public:
int id;
string name;
string issue;
Request(int i, string n, string is){
        id=i;
        name=n;
        issue=is;
    }
};

//node of queue
class Node{
public:
Request data;
Node *next;
Node(Request r):data(r),next(NULL){}
};

//own queue class (linked list based, FIFO)
class MyQueue{
Node *frontNode, *rearNode;
int count;

public:
MyQueue():frontNode(NULL),rearNode(NULL),count(0){}
~MyQueue(){
while(!empty())
pop();
    }

bool empty(){return count==0;}
int size(){return count;}

    //add at rear
void push(Request r){
Node *nN=new Node(r);
if(!rearNode){
            frontNode=rearNode=nN;
        }else{
            rearNode->next=nN;
            rearNode=nN;
        }
        count++;
    }

    //remove from front
void pop(){
if(empty()){
            cout<<"Queue is empty.\n";return;
        }
Node *del=frontNode;
        frontNode=frontNode->next;
if(!frontNode) rearNode=NULL;
delete del;
        count--;
    }

    //request which is at front (use only when queue is not empty)
Request &front(){
return frontNode->data;
    }
};

//help desk class
class HelpDesk{
MyQueue q;
int nextId;

    //show one request
void show(Request &r){
        cout<<"ID: "<<r.id<<endl;
        cout<<"Student name: "<<r.name<<endl;
        cout<<"Issue: "<<r.issue<<endl;
    }

//====================== public =====================================
public:
HelpDesk():nextId(1){}

    //add new request at the back of queue
void addRequest(){
string name, issue;
        cout<<"Enter student name: ";
getline(cin,name);
        cout<<"Enter issue: ";
getline(cin,issue);

if(name.empty() || issue.empty()){
            cout<<"Name and issue can not be empty.\n";return;
        }

        q.push(Request(nextId,name,issue));
        cout<<"Request added successfully. Your ID is "<<nextId<<endl;
        nextId++;
    }

    //serve (remove) the request which is at the front
void serveRequest(){
if(q.empty()){
            cout<<"No request is waiting.\n";return;
        }
        cout<<"Serving request:\n";
show(q.front());
        q.pop();
        cout<<"Request served successfully.\n";
    }

    //view next request without removing it
void viewNext(){
if(q.empty()){
            cout<<"No request is waiting.\n";return;
        }
        cout<<"Next request:\n";
show(q.front());
    }

    //count waiting requests
void waitingCount(){
        cout<<"Waiting requests: "<<q.size()<<endl;
    }
};

int main(){
HelpDesk desk;
int ch;

while(true){
        cout<<"\n===== Campus Help Desk =====\n";
        cout<<" 1- Add request\n 2- Serve next request\n 3- View next request\n 4- Waiting count\n 0- Exit\n";
        cout<<"Enter choice: ";

if(!(cin>>ch)){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Invalid choice......\n";
continue;
        }
        cin.ignore(1000,'\n');

switch(ch){
case 1:
            desk.addRequest();
break;

case 2:
            desk.serveRequest();
break;

case 3:
            desk.viewNext();
break;

case 4:
            desk.waitingCount();
break;

case 0:
            cout<<"Exiting.......\n";
return 0;

default:
            cout<<"Invalid choice......\n";
        }
    }
}
