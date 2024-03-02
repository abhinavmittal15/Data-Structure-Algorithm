#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> nums2;
        for(int i=0; i<nums.size() ; i++){
            nums2.push_back(nums[i]*nums[i]);
        }
        sort(nums2.begin(), nums2.end());
        return nums2;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> ans = sol.sortedSquares(nums);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}