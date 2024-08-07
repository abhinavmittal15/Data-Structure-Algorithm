#include<iostream>
using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        
        if ((n | k) != n) {
            // k contains bits that are not in n, making it impossible to convert
            return -1;
        }
        
        int changes = 0;
        int xorResult = n ^ k;  // XOR to find bits that differ
        
        // Count the number of 1s in xorResult
        while (xorResult > 0) {
            changes += xorResult & 1;
            xorResult >>= 1;
        }
        
        return changes;
    }
};

int main(){
    Solution s;
    int n = 13;
    int k = 4;
    cout << s.minChanges(n, k) << endl;
    return 0;
}