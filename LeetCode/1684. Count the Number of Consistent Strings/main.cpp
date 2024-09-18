#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> mp;
        for (char c : allowed) {
            mp[c] = 1;
        }
        int res = 0;
        for (string word : words) {
            bool flag = true;
            for (char c : word) {
                if (mp.find(c) == mp.end()) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution obj;
    string allowed = "ab";
    vector<string> words = {"ad","bd","aaab","baa","badab"};
    cout << obj.countConsistentStrings(allowed, words) << endl;
    return 0;
}