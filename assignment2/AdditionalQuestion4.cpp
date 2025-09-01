#include <iostream>
using namespace std;

void dutchsort(int arr[],int n){
    int s = 0;
    int mid = 0;
    int e = n-1;
    while(mid<=e){
        if(arr[mid]==0){
            swap(arr[s],arr[mid]);
            s++;
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[e]);
            e--;
        }
        else {
            mid++;
        }
    }
}

int main()
{
    int arr[] = {0,1,2,0,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    dutchsort(arr,n);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
