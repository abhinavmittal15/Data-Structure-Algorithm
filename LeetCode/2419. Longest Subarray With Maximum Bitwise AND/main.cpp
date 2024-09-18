#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int ans = 1;
        int curr = 1;
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] == nums[i+1] && nums[i] == maxNum) {
                curr++;
                ans = max(ans, curr);
            }
            else{
                curr = 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, 3, 2, 2};
    cout << obj.longestSubarray(nums) << endl;
    return 0;
}