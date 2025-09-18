#include<iostream>
#include<stack>
#include<string>
using namespace std;
int operation(char s,int a,int b){
    switch(s){
        case '+' :
        return a+b;
        break;
        case '-' :
        return a-b;
        break;
        case '*' :
        return a*b;
        break;
        case '/' :
        return a/b;
        break;
    }
    return -1;
}
int postfix_evaluation(string &s){
    stack <int> st;
    for(int i =0;i<s.length();i++){
        if(isdigit(s[i])){
            st.push(s[i]-'0');
        }
        else{
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int c = operation(s[i],b,a);
            st.push(c);
        }
    }
    return st.top();
}
int main(){
    string post = "63/2*5+";
    cout<<"result is: "<<postfix_evaluation(post)<<endl;
}
