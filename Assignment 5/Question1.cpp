#include<iostream>
using namespace std;

class Node {
  public:
  int data;
  Node* next;
  Node(){
      next = NULL;
      data = 0;
  }
  Node(int data){
      this->data = data;
      this->next = NULL;
  }
};

class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head = NULL;
    }
    void insert_beg(int num);
    void insert_end(int num);
    void insert_between(int num,int a,int b);
    void delete_beg();
    void delete_end();
    void delete_specific(int num);
    void display_position(int num);
    void display_all();
};

void LinkedList::insert_beg(int num){
     Node* newnode = new Node();
     newnode->next = head;
     newnode->data = num;
     head = newnode;
     
 }
 
void LinkedList::insert_end(int num){
    Node* newnode = new Node();
    newnode->data = num;
    if(head==NULL){
        head = newnode;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    
}

void LinkedList::insert_between(int num,int a,int b){
    Node* newnode = new Node(num);
    Node* temp = head;
    while(temp->data != a && temp->next->data != b){
        temp = temp->next;
    }
    if(temp->data != a && temp->next->data != b){
        cout<<"SUCH VALUES DOES NOT EXISTS";
        return;
    }
    else{
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void LinkedList::delete_beg(){
    if(head == NULL){
        cout<<"LIST IS EMPTY";
    }
    else{
        Node* temp = head;
        head = temp->next;
    }
}

void LinkedList::delete_end(){
    if(head==NULL){
        cout<<"LIST IS EMPTY";
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    if(temp == head){
        head = NULL;
    }
    else{
        prev-> next = NULL;
    }
}

void LinkedList::delete_specific(int num){
    Node* temp = head;
    Node* prev = NULL;
    while(temp!= NULL&&temp->data!=num){
        prev = temp;
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<"ELEMENT NOT PRESENT";
        return;
    }
    else if(temp == head){
        head = temp->next;
        return;
    }
    else if(temp->next==NULL){
        prev->next = NULL;
    }
    else{
        prev->next = temp->next;
    }
}

void LinkedList::display_position(int num){
    int count = 1;
    Node* temp = head;
    while(temp->data!=num&&temp!=NULL){
        temp = temp->next;
        count++;
    }
    if(temp==NULL){
        cout<<"ELEMENT NOT PRESENT";
        return;
    }
    cout<<"ELEMENT IS PRESENT AT "<<count<<endl;
}

void LinkedList::display_all(){
    Node* temp = head;
    if(temp == NULL){
        cout<<"LIST IS EMPTY"<<endl;
        return;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


int main(){
    LinkedList list;
}
