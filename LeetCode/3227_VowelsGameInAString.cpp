#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {  
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    string str = "leetcode";
    cout << s.doesAliceWin(str) << endl;
    return 0;
}