#include<iostream>
#include<string>
#include<algorithm>
#include<regex>
using namespace std;

class Solution {
public:
    bool isPalindrome(string str) {
        // regex vowels(",|:| |.");
        regex non_alphanumeric("\\W|_");
        str = regex_replace(str, non_alphanumeric, "");
        for (char &c : str) {
            c = tolower(c);  //here s is converted to lowercase
        }
        string rts = str;

        reverse(str.begin(), str.end());
        if(rts == str){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    Solution s;
    string str = "A man, a plan, a canal: Panama";
    cout << s.isPalindrome(str) << endl;
    return 0;
}