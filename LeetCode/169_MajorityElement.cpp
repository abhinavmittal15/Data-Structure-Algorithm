#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};

int main(){
    Solution s;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << s.majorityElement(nums) << endl;
    return 0;
}