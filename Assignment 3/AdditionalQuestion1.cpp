#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[] = {5,10,7,2,4,16,1};
    stack <int> s;
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans[7];
    for(int i = 0;i<n;i++){
        while(!s.empty()&&s.top()>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }
        else {
            ans[i]=s.top();
        }
        s.push(arr[i]);
    }
    for(int i = 0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
