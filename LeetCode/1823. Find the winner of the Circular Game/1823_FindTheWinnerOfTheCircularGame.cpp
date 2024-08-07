#include<iostream>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0; // Start with the base case
        for (int i = 2; i <= n; ++i) {
            winner = (winner + k) % i;
        }
        return winner + 1; // Adjusting the index to match 1-based indexing
    }
};

int main(){
    Solution s;
    int n = 5;
    int k = 2;
    cout << s.findTheWinner(n, k) << endl;
    return 0;
}