#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;
        
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                // sum = sum + nums[i][j];
                sum = sum + nums[j];
                arr.push_back(sum);
            }
        }
        sort(arr.begin(), arr.end());
        
        int ans = accumulate(arr.begin() + left - 1, arr.begin() + right, 0);
        // for(int i= left-1; i<right; i++){
        //     ans = ans + arr[i];
        // }
        return ans;
    }
};

int main(){
    Solution s;;
    vector<int> nums = {1, 2, 3, 4};
    int n = 4;
    int left = 1;
    int right = 5;
    cout << s.rangeSum(nums, n, left, right) << endl;
    return 0;
}