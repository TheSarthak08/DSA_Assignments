#include<iostream>
using namespace std;
class ArrayQueue{
    int front,rear,maxsize;
    int* arr;
    public:
    ArrayQueue(){
        maxsize = 16;
        arr = new int[maxsize];
        front = -1;
        rear = -1;
    }
    void enqueue(int x){
        if(rear ==maxsize-1){
            cout<<"OVERFLOW"<<endl;
        }
        else if(front==-1&&rear==-1){
            arr[++rear]=x;
            front++;
        }
        else{
            arr[++rear]=x;
        }
    }
    void dequeue(){
        if(front==-1&&rear==-1){
            cout<<"UNDERFLOW"<<endl;
        }
        else if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = front +1;
        }
    }
    bool isempty(){
        if(front==-1&&rear==-1){
            return 1;
        }
        return 0;
    }
    bool isfull(){
        return(rear==maxsize-1);
    }
    void peek(){
        cout<<arr[front];
    }
    void display(){
        for(int i = front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    ~ArrayQueue(){
        delete[]arr;
    }
};
int main(){
    ArrayQueue Q;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.display();
    Q.dequeue();
    Q.enqueue(3);
    Q.display();
}
