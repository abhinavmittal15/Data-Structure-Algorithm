// Link : https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++) {
            sum = sum + arr[i];
            maxi = max(maxi, sum);
            if(sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << obj.maxSubarraySum(arr) << endl;
    return 0;
}