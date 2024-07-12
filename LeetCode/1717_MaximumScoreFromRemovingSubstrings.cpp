#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // If x is less than y, reverse the string and swap values of x and y to 
        // prioritize removing "ba" before "ab" since we want to maximize the gain
        if (x < y) {
            reverse(s.begin(), s.end());
            // return maximumGain(s, y, x);
            swap(x, y);
        }
        // Variable to store the total gain
        int totalGain = 0;
        stack<char> stkAb; // Stack to manage "ab" pairs
        stack<char> stkBa; // Stack to manage "ba" pairs

        // Iterate through the characters of the string
        for (char c : s) {
            // If the current character is 'a' or it's not 'b', push it onto stkAb
            if (c != 'b')
                stkAb.push(c);
            else {
                // If the top of stkAb is 'a', we found "ab" so we pop 'a' and 
                // add x to totalGain
                if (!stkAb.empty() && stkAb.top() == 'a') {
                    stkAb.pop();
                    totalGain += x;
                } else {
                    // Otherwise, push 'b' to stkAb
                    stkAb.push(c);
                }
            }
        }

        // While stkAb is not empty, we will manage "ba" pairs
        while (!stkAb.empty()) {
            char c = stkAb.top();
            stkAb.pop();
            // If the current character is 'a' or it's not 'b', push it onto stkBa
            if (c != 'b')
                stkBa.push(c);
            else {
                // If the top of stkBa is 'a', we found "ba" so we pop 'a' and 
                // add y to totalGain
                if (!stkBa.empty() && stkBa.top() == 'a') {
                    stkBa.pop();
                    totalGain += y;
                } else {
                    // Otherwise, push 'b' to stkBa
                    stkBa.push(c);
                }
            }
        }

        // Return the calculated total gain
        return totalGain;
    }
};

int main(){
    Solution sol;
    cout << sol.maximumGain("cdbcbbaaabab", 4, 5) << endl;
    return 0;
}