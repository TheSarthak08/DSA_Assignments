#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(){
        data = 0;
        next = nullptr;
    }
    node(int data){
        this->data = data;
        this->next = nullptr;
    }
};
class linkedlist(){
    node* head;
    public:
    linkedlist(){
        head = null;
    }
}

void insertbeg(int x){
    node*n = new node;
    n->next = head;
    n->data = x;
    head = n;
}

void insertend(int x){
    node* n = new node();
    n->data = x;
    if(head==nullptr){
        head = n;
        return;
    }
    node* temp = head;

    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = n;
}
void insertafter(int x,int value){
    node* n = new node;
    n->data = x;
    if(head ==nullptr){
        head = n;
        return;
    }
    node* temp = head;
    while(temp!=nullptr&&temp->data!=value){
        temp = temp->next;
    }
    if(temp == nullptr){
        cout<<"NO SUCH VALUE EXISTS"<<endl;
    }
    n->next = temp->next;
    temp -> next = n;
    
}
void deletebeg(){
    if(head==nullptr){
        cout<<"LIST IS EMPTY"<<endl;
        return;
    }
    node* temp = head;
    head = temp->next;
    delete temp;
}
void deleteend(){
    if(head==nullptr){
         cout<<"LIST IS EMPTY"<<endl;
        return;
    }
    node* temp = head;
    node* prev = nullptr;
    while(temp->next!=nullptr){
        prev = temp;
        temp = temp->next;
    }
    if(temp == head){
        head = nullptr;
        delete temp;
        return;
    }
    prev->next = nullptr;
    delete temp;
}
void deletespecific(int value){
    node* temp = head;
    node* prev = temp;
    if(head == nullptr){
        cout<<"LIST IS EMPTY"<<endl;
        return;
    }
    while(temp!=nullptr&&temp->data!=value){
        prev = temp;
        temp = temp->next; 
    }
    if(temp==nullptr){
        cout<<"VALUE DOES NOT EXISTS"<<endl;
        return;
    }
    if(temp==head){
        head = head->next;
    }
    else if(temp->next==nullptr){
        prev->next = nullptr;
    }
    else{
    prev->next=temp->next;
    }
    delete temp;
}
void search(int value){
    node* temp = head;
    int count = 1;
    if(head==nullptr){
        cout<<"LIST IS EMPTY"<<endl;
        return ;
    }
    while(temp->next!=nullptr&&temp->data==value){
        temp = temp->next;
        count++;
    }
    if(temp->next==nullptr){
        cout<<"VALUE DOES NOT EXISTS"<<endl;
    }
    else
    cout<< count<<endl;
}
void display(){
    node* temp = head;
    if(head==nullptr){
        cout<<"LIST IS EMPTY"<<endl;
        return;
    }
    while(temp!=nullptr){
        cout<<temp->data;
        temp = temp->next;
    }
}
int main() {
    int choice, val, key;
    do {
        cout << "\nMenu:\n"
             << "1. Insert at beginning\n"
             << "2. Insert at end\n"
             << "3. Insert after a value\n"
             << "4. Delete from beginning\n"
             << "5. Delete from end\n"
             << "6. Delete a specific node\n"
             << "7. Search a value\n"
             << "8. Display list\n"
             << "0. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: "; cin >> val;
                insertbeg(val);
                break;
            case 2:
                cout << "Enter value: "; cin >> val;
                insertend(val);
                break;
            case 3:
                cout << "Value to insert: "; cin >> val;
                cout << "Insert before which key: "; cin >> key;
                insertafter(key, val);
                break;
            case 4: deletebeg(); break;
            case 5: deleteend(); break;
            case 6:
                cout << "Delete which value: "; cin >> key;
                deletespecific(key);
                break;
            case 7:
                cout << "Search value: "; cin >> key;
                search(key);
                break;
            case 8: display(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
