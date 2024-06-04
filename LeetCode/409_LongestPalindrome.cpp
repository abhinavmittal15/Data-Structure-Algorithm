#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(128, 0);
        for(char c : s){
            count[c]++;
        }
        int n = 0;
        for(int c : count){
            n += c/2 * 2;
            if(n % 2 == 0 && c % 2 == 1){
                n++;
            }
        }
        return n;
    }
};

int main(){
    Solution sol;
    string s = "abccccdd";
    cout << sol.longestPalindrome(s) << endl;
    return 0;
}