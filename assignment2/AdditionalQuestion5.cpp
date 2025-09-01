#include <iostream>
using namespace std;

void duplicate2(int arr[]){
    int newarr[20];
    int j = 0;
    for(int i = 0;i<8;i++){
       newarr[j++] = arr[i];
       if(arr[i]==2){
           newarr[j++]=2;
       }
    }
    for(int i = 0;i<j;i++){
        cout<<newarr[i]<<" ";
    }
}

int main(){
    int arr[8] = {1,2,0,3,2,4,5,2};
    duplicate2(arr);
    return 0;
}
