// Link : https://www.naukri.com/code360/problems/count-square-submatrices-with-all-ones_3751502

#include<bits/stdc++.h>
using namespace std;

int countSquares(int n, int m, vector<vector<int>> &arr) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i=0; i<n; i++) {
        dp[i][0] = arr[i][0];
    }
    for(int j=0; j<m; j++) {
        dp[0][j] = arr[0][j];
    }
    int sum = 0;
    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(arr[i][j] == 1) {
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    for(int i=0; i<n; i++) {
        for (int j = 0; j < m; j++) {
            sum += dp[i][j];
        }
    }
    return sum;
}

int main() {
    int n;
    cin>>n;
    
    int m;
    cin>>m;

    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }


    cout << countSquares(n, m, arr) << endl;
    return 0;
}