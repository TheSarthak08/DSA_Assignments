//(a) Write a program to concatenate one string to another string.

#include <iostream>
#include <string>
using namespace std;


int main(){
    string a = "Hello ";
    string b = "world";
    string c = a+b;
    cout<<c<<endl;
}


//(b) Write a program to reverse a string.




#include <iostream>
#include <string>
#include<algorithm>
using namespace std;


int main(){
    string abc;
    char temp;
    cout<<"Enter a string: ";
    getline (cin,abc);
    int n = abc.length();
    for(int i = 0;i<n/2;i++){
        temp=abc[i];
        abc[i]=abc[n-1-i];
        abc[n-1-i]=temp;
        
    }
    cout<<abc<<endl;
}



//(c) Write a program to delete all the vowels from the string.


#include <iostream>
#include <string>
#include<algorithm>
using namespace std;


int main(){
    string abc;
    string ans;
    cout<<"Enter a string: ";
    getline (cin,abc);
    int n = abc.length();
    for(int i = 0;i<n;i++){
        if(abc[i]=='a'||abc[i]=='e'||abc[i]=='i'||abc[i]=='o'||abc[i]=='u'){
            continue;
        }
        ans.push_back(abc[i]);
        
    }
    cout<<ans<<endl;
}



//(d) Write a program to sort the strings in alphabetical order.


#include <iostream>
#include <string>
#include<algorithm>
using namespace std;


string sortstrings(string abc,int n){
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-1-i;j++){
            if(abc[j]>abc[j+1]&&abc[j]!=' '&&abc[j+1]!=' '){
                swap(abc[j],abc[j+1]);
            }
        }
    }
    return abc;
}

int main(){
    string abc;
    getline(cin,abc);
    int n = abc.length();
    string ans = sortstrings(abc,n);
    cout<<ans<<endl;
}





//(e) Write a program to convert a character from uppercase to lowercase.



#include <iostream>
#include <string>
using namespace std;
string upperlower(string abc,int n){
    int x = 'a'-'A';
    for(int i = 0;i<n;i++){
        if(abc[i]>='A'&&abc[i]<='Z'){
            abc[i]=abc[i]+x;
        }
        else if(abc[i]>='a'&&abc[i]<='z'){
            abc[i]=abc[i]- x;
        }
    }
    return abc;
}
int main() {
    string abc;
    getline(cin,abc);
    int n = abc.length();
    string ans = upperlower(abc,n);
    cout<<ans<<endl;
}
