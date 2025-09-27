#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void printqueue(queue <int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
void interleave(queue<int> &q){
    stack <int> s;
    int halfsize = q.size()/2;
    for(int i = 0;i<halfsize;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for(int i = 0;i<halfsize;i++){
        q.push(q.front());
        q.pop();
    }
    for(int i = 0;i<halfsize;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}
int main(){
    queue<int> q;
    q.push(4); q.push(7); q.push(11); q.push(20); q.push(5); q.push(9);
    printqueue(q);
    interleave(q);
    printqueue(q);
}
