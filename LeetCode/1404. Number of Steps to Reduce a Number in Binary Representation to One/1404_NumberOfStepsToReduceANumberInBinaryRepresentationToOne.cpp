#include<iostream>
#include<cmath>
#include<string>

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while (s != "1") {
            if (s.back() == '0') {
                s.pop_back();  // divide by 2
            } else {
                for (int i = s.size() - 1; i >= 0; --i) {
                    if (s[i] == '1') {
                        s[i] = '0';
                    } else {
                        s[i] = '1';
                        break;
                    }
                    if (i == 0) {
                        s.insert(s.begin(), '1');
                    }
                }
            }
            ++steps;
        }
        return steps;
    }
};

int main() {
    Solution sol;
    string s = "1111011110000011100000110001011011110010111001010111110001";
    cout << sol.numSteps(s) << endl;
    return 0;
}