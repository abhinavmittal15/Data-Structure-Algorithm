#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> toRemove;
        vector<int> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push_back(i);
            } else if (s[i] == ')') {
                if (stack.empty()) {
                    toRemove.push_back(i);
                } else {
                    stack.pop_back();
                }
            }
        }
        for (int i : stack) {
            toRemove.push_back(i);
        }
        string ans;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (j < toRemove.size() && i == toRemove[j]) {
                j++;
            } else {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};


int main(){
    Solution s;
    string str = "lee(t(c)o)de)";
    cout << s.minRemoveToMakeValid(str) << endl;
    return 0;
}