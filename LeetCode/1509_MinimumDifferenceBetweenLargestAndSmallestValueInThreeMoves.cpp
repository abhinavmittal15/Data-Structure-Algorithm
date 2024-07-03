#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        // If the array has 4 or fewer elements, we can make all elements equal
        if (nums.size() <= 4) return 0;

        // Sort the array to easily find the minimum and maximum elements
        sort(nums.begin(), nums.end());

        int n = nums.size();
        // We have four options to minimize the difference:
        // 1. Change the three largest elements, so the difference is nums[n-4] - nums[0]
        // 2. Change the two largest and one smallest elements, so the difference is nums[n-3] - nums[1]
        // 3. Change the one largest and two smallest elements, so the difference is nums[n-2] - nums[2]
        // 4. Change the three smallest elements, so the difference is nums[n-1] - nums[3]
        // The minimum difference out of these options will be our answer
        return min({nums[n-4] - nums[0], nums[n-3] - nums[1], nums[n-2] - nums[2], nums[n-1] - nums[3]});
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,5,0,10,14};
    cout << s.minDifference(nums) << endl;
    return 0;
}