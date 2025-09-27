#include<iostream>
using namespace std;
class ArrayQueue{
    int front,rear,maxsize,currentsize;
    int* arr;
    public:
    ArrayQueue(){
        maxsize = 5;
        arr = new int[maxsize];
        front = -1;
        rear = -1;
        currentsize=0;
    }
    void enqueue(int x){
        if((rear+1)%maxsize ==front){
            cout<<"OVERFLOW"<<endl;
        }
        else if(front==-1&&rear==-1){
            arr[++rear]=x;
            front++;
            currentsize++;
        }
        else{
            rear = (rear+1)%maxsize;
            arr[rear]=x;
            currentsize++;
        }
    }
    void dequeue(){
        if(front==-1&&rear==-1){
            cout<<"UNDERFLOW"<<endl;
        }
        else if(front == rear){
            front = -1;
            rear = -1;
            currentsize--;
        }
        else{
            front = (front +1)%maxsize;
            currentsize--;
        }
    }
    bool isempty(){
        if(currentsize==0){
            return 1;
        }
        return 0;
    }
    bool isfull(){
        return(currentsize==maxsize);
    }
    void peek(){
        cout<<arr[front];
    }
    void display(){
        int i = front;
        for(int count = 0;count<currentsize;count++){
            cout<<arr[i]<<" ";
            i = (i+1)%maxsize;
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
    Q.enqueue(3);Q.enqueue(4);Q.enqueue(5);Q.enqueue(2);
    Q.display();
    Q.dequeue();Q.dequeue();Q.dequeue();Q.dequeue();
    Q.enqueue(10);
    Q.enqueue(20);
    Q.display();
    
}
