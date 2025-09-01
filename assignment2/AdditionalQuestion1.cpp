#include <iostream>
#include<algorithm>
using namespace std;

int difference(int arr[],int k,int n){
    int s = 0;
    int e = 1;
    int count = 0;
    sort(arr,arr+n);
    while(e<n){
        if(e==s){
            int ele1 = arr[s], ele2 = arr[e];
            int cnt1 = 0, cnt2 = 0;
          
            
            while(e < n && arr[e] == ele2) {
                e++;
                cnt2++;
            }
          
           
            while(s < n && arr[s] == ele1) {
                s++;
                cnt1++;
            }
            count = count + cnt1+cnt2;
        }
        if(arr[e]-arr[s]==k){
            count++;
            e++;
        }
        else if (arr[e]-arr[s]>k){
            s++;
        }
        else{
            e++;
        }
    }
    return count;
}

int main()
{
    int arr[] = {1,4,1,4,5};
    int key = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<difference(arr,key,n);
}
