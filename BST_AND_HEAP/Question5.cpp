#include<iostream>
#include<algorithm>
using namespace std;

int left(int i){
    return (2*i+1);
}
int right(int i){
    return (2*i+2);
}


void max_heapify(int arr[],int i,int n){
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l<n&&arr[l]>arr[i]){
        largest = l;
    }
    if(r<n&&arr[r]>arr[largest]){
        largest = r;
    }
    if(largest == i){
        return;
    }
    else {
        swap(arr[i],arr[largest]);
        max_heapify(arr,largest,n);
    }
}

void build_maxheap(int arr[],int n){
    for(int i = n/2;i>=0;i--){
        max_heapify(arr,i,n);
    }
}

void heapsort(int arr[],int n){
    build_maxheap(arr,n);
    for(int i = n-1;i>0;i--){
        swap(arr[0],arr[i]);
        max_heapify(arr,0,i);
    }
}


void display(int arr[],int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[10] = {4,1,3,2,16,9,10,14,8,7};
    int n = 10;
    heapsort(arr,n);
    display(arr,n);
}
