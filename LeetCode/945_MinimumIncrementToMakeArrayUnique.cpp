#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int minIncrementForUnique(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                ans += nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1] + 1;
            }
        }
        return ans;
    }      
};

int main(){
    Solution s;
    vector<int> nums = {3, 2, 1, 2, 1, 7};
    cout << s.minIncrementForUnique(nums) << endl;
    return 0;
}