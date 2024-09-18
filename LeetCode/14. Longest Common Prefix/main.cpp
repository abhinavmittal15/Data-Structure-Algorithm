#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        int commonLen = strs[0].length();
        for(int i=0; i<strs.size(); i++) {
            int j = 0;
            while(j<strs[i].length() && j<commonLen && strs[i][j] == strs[0][j]) {
                j++;
            }
            commonLen = j;
            if (commonLen == 0) return "";
        }
        return strs[0].substr(0, commonLen);
    }
};

int main() {
    Solution obj;
    vector<string> strs = {"flower","flow","flight"};
    cout << obj.longestCommonPrefix(strs) << endl;
    return 0;
}