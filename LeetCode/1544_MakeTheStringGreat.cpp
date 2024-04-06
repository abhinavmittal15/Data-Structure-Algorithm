#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string makeGood(string s)
    {
        string ans;
        for (const char c : s)
            if (!ans.empty() && isBadPair(ans.back(), c))
                ans.pop_back();
            else
                ans.push_back(c);
        return ans;
    }

    bool isBadPair(char a, char b)
    {
        return a != b && tolower(a) == tolower(b);
    }
};

int main(){
    Solution s;
    string str = "leEeetcode";
    cout << s.makeGood(str) << endl;
    return 0;
}