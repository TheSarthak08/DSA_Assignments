#include <iostream>
using namespace std;


int binarysearch(int arr[],int n,int key){
    int s = 0;
    int e = n-1;
    int mid;
    while(s<=e){
        mid = (s+e)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
        else {
            e =mid-1;
        }
    }
    return -1;
}
int main() {
 
int arr[] = {1,2,3,4,5,6,7,8};
int n = 8;
int key;
cout << "Enter the element you want to find"<<endl;
cin>> key;
int a = binarysearch(arr,n,key);
cout<<a<<endl;
    return 0;
}
