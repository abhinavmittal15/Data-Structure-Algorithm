#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
public:
    string removeKdigits(string num, int k)    {
        if (num.length() == k)
            return "0";

        string ans;
        vector<char> stack;

        for (int i = 0; i < num.length(); ++i) {
            while (k > 0 && !stack.empty() && stack.back() > num[i]) {
                stack.pop_back();
                --k;
            }
            stack.push_back(num[i]);
        }

        while (k-- > 0)
            stack.pop_back();

        for (const char c : stack) {
            if (c == '0' && ans.empty())
                continue;
            ans += c;
        }

        return ans.empty() ? "0" : ans;
    }
};

int main(){
    string num = "1432219";
    int k = 3;
    Solution sol;
    string res = sol.removeKdigits(num, k);
    cout << res << endl;
    return 0;
}