//Write a program that checks if an expression has balanced parentheses.
#include<iostream>
#include<stack>
using namespace std;
bool checkpar(string &s){
    stack <char> st;
    int n = s.length();
    for(int i = 0;i<n;i++){
        if (s[i]=='['||s[i]=='{'||s[i]=='('){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                return false;
            }
             else if(s[i]==')'){
            if(st.top()=='('){
                st.pop();
            }
            else {
                return 0;
            }
        }
        else if(s[i]=='}'){
            if(st.top()=='{'){
                st.pop();
            }
            else {
                return 0;
            }
        }
        else if(s[i]==']'){
            if(st.top()=='['){
                st.pop();
            }
            else {
                return 0;
            }
        }
        
    }
    }
    if(st.size()!=0){
        return false;
    }
    return 1;
}
int main(){
    string s = "{()[]})";
    if(checkpar(s)){
        cout<<"BALANCED";
    }
    else{
        cout<<"NOT BALANCED";
    }
    return 0;
}
