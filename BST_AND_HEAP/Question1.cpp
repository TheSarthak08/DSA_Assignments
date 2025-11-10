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

void preorder(node* node){
    if(node == NULL){
        return;
    }
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(node* node){
    if(node == NULL){
        return;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}


void postorder(node* node){
    if(node == NULL){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}


int main(){
    node* root = new node(5);
     root->left =new node(3);
     root->right = new node(10);
     root->left->left = new node(1);
     root->left->right =new node(4);
     root->right->left = new node(7);
     root->right->right = new node(12);
    postorder(root);cout<<endl;
    preorder(root);cout<<endl;
    inorder(root);cout<<endl;
}
