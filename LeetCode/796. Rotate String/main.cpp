#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0; i<s.length(); i++) {
            if(s == goal) {
                return true;
            }
            else {
                s = s + s[0];
                s.erase(0,1);
            }
        }
        return false;
    }
};

int main() {
    Solution obj;
    string s = "abcde";
    string goal = "cdeab";
    cout << obj.rotateString(s, goal) << endl;
    return 0;
}