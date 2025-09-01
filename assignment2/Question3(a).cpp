#include <iostream>
using namespace std;


int missingelement(int arr[],int n){
    for(int i =0;i<n;i++){
    if(arr[i]!=i+1){
        return i+1;
    }
    }
    return -1;
}
int main(){
    int arr[]={2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);
    int a = missingelement(arr,n);
    cout<<a<<endl;
    return 0;
}
