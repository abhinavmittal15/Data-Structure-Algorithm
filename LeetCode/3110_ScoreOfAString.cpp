#include<iostream>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int n = s.length();
        int ans = 0;

        for(int i=0; i<n-1; i++){
            ans = ans + abs(s[i] - s[i+1]);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "hello";
    cout << sol.scoreOfString(s) << endl;
    return 0;
}