#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int num){
        data = num;
        left = NULL;
        right = NULL;
    }
};

void iterative_search(node* root,int key){
    node* temp = root;
    int height = 0;
    while(temp!=NULL){
        if(temp->data>key){
            temp = temp->left;
            height++;
        }
        else if(temp->data<key){
            temp = temp->right;
            height++;
        }
        else{
            cout<<"The element is present at height "<<height<<endl;
            return;
        }
    }
    cout<<"ELEMENT NOT FOUND!!"<<endl;
}

void recursive_search(node* root,int key,int num){
    if(root ==NULL){
        cout<<"ELEMENT NOT PRESENT"<<endl;
        return;
    }
    else{
    if(root->data==key){
        cout<<"Element is present at height "<<num;
    }
    else if(root->data>key){
        recursive_search(root->left,key,num+1);
    }
    else{
        recursive_search(root->right,key,num+1);
    }
    }
}

int Max_ELEMENT(node* root){
    node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp->data;
}

int Min_ELEMENT(node* root){
    node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp->data;
}

int successor(node* root,node* key){
    if(key->right!=NULL){
        return Min_ELEMENT(key->right);
    }
    int succ = -1;
    while(true){
        if(key->data>root->data){
            root = root->right;
        }
        else if(key->data<root->data){
            succ = root->data;
            root = root->left;
        }
        else{
            break;
        }
    }
    return succ;
}

int predecessor(node* root,node* key){
    if(key->left!=NULL){
        return Max_ELEMENT(key->left);
    }
    int pre = -1;
    while(true){
        if(key->data>root->data){
            pre = root->data;
            root = root->right;
        }
        else if(key->data<root->data){
            root = root->left;
        }
        else{
            break;
        }
    }
    return pre;
}


int main(){
    node* root = new node(5);
    root->left =new node(3);
    root->right = new node(10);
    root->left->left = new node(1);
    root->left->right =new node(4);
    root->right->left = new node(7);
    root->right->right = new node(12);
    int pre = predecessor(root,root->right);
    cout<<"PREDECESSOR IS "<<pre<<" "<<endl;
}
