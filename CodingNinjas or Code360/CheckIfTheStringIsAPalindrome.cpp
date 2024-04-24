// The link to the problem: https://www.naukri.com/code360/problems/check-if-the-string-is-a-palindrome_1062633

#include<iostream>
using namespace std;

bool checkPalindrome(string s){
    int start = 0;
    int end = s.length() - 1;

    while(start<=end){
        if( !isalnum(s[start])){
            start++;
            continue;
        }
        if(!isalnum(s[end])){
            end--;
            continue;
        }

        if(tolower( s[start] ) != tolower( s[end] ))  
            return 0;
        
        else
            start++;
            end--;
        
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    if(checkPalindrome(s)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}