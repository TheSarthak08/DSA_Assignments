#include <iostream>
using namespace std;

int uniqueelements(int arr[],int n){
    int count = 0;
    for(int i = 0;i<n;i++){
        bool isduplicate = false;
        for(int j = 0;j<n;j++){
            if(i==j){
                continue;
            }
           else if(arr[i]==arr[j]){
                isduplicate = true;
            }
        }
        if(!isduplicate){
            count++;
        }
    }
    return count;
}
int main(){
    int arr[10]= {0,1,1,3,3,5,6,7,9,9};
    cout<<uniqueelements(arr,10);
}
