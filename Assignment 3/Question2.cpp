/*Given a string, reverse it using STACK. For example “DataStructure” should be output as
“erutcurtSataD.”*/

#include <iostream>
#include<stack>
using namespace std;
void revstring(string &s){
    stack <char> st;
    int n = s.length();
    for(int i = 0;i<n;i++){
        st.push(s[i]);
    }
    for(int i = 0;i<n;i++){
        s[i]=st.top();
        st.pop();
    }
}
int main(){
    string s = "Data Structure";
    revstring(s);
    cout<<s;
    return 0;
}
