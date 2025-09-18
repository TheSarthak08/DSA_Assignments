#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int priority(char a){
    if(a=='+'||a=='-'){
        return 1;
    }
    else if(a=='*'||a=='/'){
        return 2;
    }
    else if(a=='^'){
        return 3;
    }
    else
    return -1;
}
string convert_to_postfix(string &s){
    stack <char> st;
    string ans = "";
    int n = s.length();
    for(int i = 0;i<n;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            ans = ans + s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty()&&st.top()!='('){
                ans = ans + st.top();
                st.pop();
            }
            if(st.top()=='('){
                st.pop();
            }
        }
        else{
            while(!st.empty()&&priority(s[i])<=priority(st.top())){
                ans = ans+ st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        
    }
    while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }
    return ans;
}
int main(){
    string infix = "A+B*C";
    string postfix = convert_to_postfix(infix);
    cout<<postfix;
    return 0;
}
