#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums){
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxNum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0 && numSet.count(-nums[i])){
                maxNum = max(maxNum, nums[i]);
            }
        }
        return maxNum > 0 ? maxNum : -1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {-1, 2, -3, 3};
    cout << s.findMaxK(nums) << endl;
    return 0;
}