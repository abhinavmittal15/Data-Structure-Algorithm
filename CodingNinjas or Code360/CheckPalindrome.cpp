//The link to the problem : https://www.naukri.com/code360/problems/check-palindrome_4219630

#include<iostream>
using namespace std;

bool isPalindrome(string& s){
    int n = s.length();
    for(int i=0; i<n/2; i++)
        if(s[i] != s[n-i-1]) return false;
    return true;
}

int main(){
    string s = "racecar";
    cout << isPalindrome(s) << endl;
    return 0;
}