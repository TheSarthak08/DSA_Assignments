#include <bits/stdc++.h>
using namespace std;

bool isSubstring(string str1, string str2) {
    if(str1.length() > str2.length()) 
        return false;
    
    for(int i = 0; i <= str2.length() - str1.length(); i++) {
        bool found = true;
        for(int j = 0; j < str1.length(); j++) {
            if(str2[i + j] != str1[j]) {
                found = false;
                break;
            }
        }
        if(found) return true;
    }
    return false;
}

bool checkPossible(string str) {
    int n = str.length();
    
    
    for(int i = 1; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            // Get three parts
            string part1 = str.substr(0, i);
            string part2 = str.substr(i, j-i);
            string part3 = str.substr(j);
            
            
            if(part1.empty() || part2.empty() || part3.empty()) 
                continue;
                
           
            if(isSubstring(part1, part2) && isSubstring(part1, part3)) return true;
            if(isSubstring(part2, part1) && isSubstring(part2, part3)) return true;
            if(isSubstring(part3, part1) && isSubstring(part3, part2)) return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        string str;
        cin >> str;
        
        if(checkPossible(str))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
