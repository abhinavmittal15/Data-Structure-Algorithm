#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        const int zeroes = count(s.begin(), s.end(), '0');
        const int ones = s.length() - zeroes;
        return string(ones - 1, '1') + string(zeroes , '0') + '1';
    }
};

int main() {
    Solution sol;
    string s ;
    cin >> s;
    string ans = sol.maximumOddBinaryNumber(s);
    cout << ans << endl;
    return 0;
}