#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int fib(int n){
        if(n <= 1)
            return n;

        vector<int> dp{0,0,1};
        for(int i=2; i<=n; i++){
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = dp[0] + dp[1];
        }
        return dp[2];
    }
};

int main(){
    Solution s;
    int n = 5;
    cout << s.fib(n) << endl;
    return 0;
}