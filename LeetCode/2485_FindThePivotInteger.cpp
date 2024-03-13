#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        const int y = (n * n + n) / 2;
        const int x = sqrt(y);
        return x * x == y ? x : -1;
    }
};

int main(){
    Solution s;
    int n = 8;
    cout << s.pivotInteger(n) << endl;
    return 0;
}