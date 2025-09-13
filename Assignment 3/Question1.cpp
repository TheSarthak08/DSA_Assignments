/*Develop a menu driven program demonstrating the following operations on a Stack using array:
(i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().*/

#include <iostream>
#define max 5
using namespace std;

class stack{
    int top;
    int arr[max];
    public:
    stack(){
        top=-1;
    }
    bool isempty(){
        return(top==-1);
    }
    bool isfull(){
        return(top==max-1);
    }
    void push(int n){
        if(isfull()){
            cout<<"STACK OVERFLOW"<<endl;
        }
        else{
            arr[++top]=n;
        }
    }
    void pop(){
        if(isempty()){
            cout<<"STACK UNDERFLOW"<<endl;
        }
        else{
            cout<<arr[top--]<<" popped from the stack"<<endl;
        }
    }
    void display(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
        }
        else{
            for(int i = top;i>=0;i--){
                cout<<arr[i]<<endl;
            }
        }
    }
    void peek(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
        }
        else{
            cout<<arr[top]<<endl;
        }
    }
};

int main() {
    stack s;
    if(s.isempty()){
        cout<<"stack is empty"<<endl;
    };
    if(s.isfull()){
        cout<<"stack is full"<<endl;
    };
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.display();
    s.peek();
    s.pop();
    s.pop();s.pop();s.pop();s.pop();
    return 0;
}
