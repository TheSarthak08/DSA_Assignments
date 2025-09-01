#include <iostream>
using namespace std;


int missingelement(int arr[],int n){
    int s = 0;
    int e = n-1;
    int mid;
    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid]==mid+1){
            s = mid+1;
        }
        else if(arr[mid]!= mid+1 && arr[mid-1]==mid){
            return mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,9};
    int n = sizeof(arr)/sizeof(int);
    int a = missingelement(arr,n);
    cout<<a<<endl;
    return 0;
}
