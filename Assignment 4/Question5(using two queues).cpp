#include<iostream>
#include<queue>
using namespace std;
void push(queue <int> &q,int x){
    queue <int> temp;
    int a = q.size();
    while(!q.empty()){
        temp.push(q.front());
        q.pop();
    }
    q.push(x);
    while(!temp.empty()){
        q.push(temp.front());
        temp.pop();
    }
}
void display(queue <int> q){
    int a = q.size();
        for(int i = 0;i<a;i++){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;
    }
int main(){
    queue <int> q;
    push(q,10);
    push(q,20);
    push(q,30);
    display(q);
    q.pop();
    push(q,40);
    display(q);
}
