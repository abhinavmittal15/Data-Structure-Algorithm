#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> count;
        int l = 0;
        for(int r=0 ; r < nums.size() ; r++){
            count[nums[r]]++;
            while(count[nums[r]] == k+1)
                count[nums[l++]]--;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,1,2,3,1,2};
    int k = 2;
    cout<<s.maxSubarrayLength(nums, k)<<endl;
    return 0;
}