#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26);
        for (const char c : s) {
            const int i = c - 'a';
            dp[i] = 1 + getMaxReachable(dp, i, k);
        }
        return *max_element(dp.begin(), dp.end());
    }
    
private:
    int getMaxReachable(const vector<int>& dp, int i, int k) {
        const int first = max(0, i - k);
        const int last = min(25, i + k);
        int maxReachable = 0;
        for (int j = first; j <= last; ++j)
            maxReachable = max(maxReachable, dp[j]);
        return maxReachable;
    }
};

int main() {
    Solution sol;
    string s = "acfgbd";
    int k = 2;
    cout << sol.longestIdealString(s, k) << endl;
    return 0;
}