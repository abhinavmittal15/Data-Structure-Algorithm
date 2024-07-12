// Link : https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0

#include<iostream>
using namespace std;

class Solution {
public:
    long long pairWithMaxSum(long long arr[], long long n) {
        long long maxi = 0 ;
        for (int i = 1; i < n; i++)
            maxi = max(maxi, arr[i] + arr[i-1]);
        return maxi;
    }
};

int main(){
    Solution s;
    long long arr[] = {1, 2, 3, 1, 2};
    long long n = sizeof(arr)/sizeof(arr[0]);
    cout << s.pairWithMaxSum(arr, n) << endl;
    return 0;
}