#include <iostream>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int opened = 0;

        for (const char c : s){
            if (c == '(') {
                ans = max(ans, ++opened);
            }
            
            else if (c == ')'){
                opened--;
            }
        }
        return ans;
    }
};

int main() {
    Solution S;
    string test_case1 = "(1+(2*3)+((8)/4))+1";
    cout << "Test Case 1: " << S.maxDepth(test_case1) << endl; // Expected output: 3

    string test_case2 = "(1)+((2))+(((3)))";
    cout << "Test Case 2: " << S.maxDepth(test_case2) << endl; // Expected output: 3

}