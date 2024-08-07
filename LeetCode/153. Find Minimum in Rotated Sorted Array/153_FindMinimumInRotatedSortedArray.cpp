#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int mini = INT_MAX;
        while(s <= e){
            if(nums[s] < nums[e]){
                mini = min(mini, nums[s]);
                break;
            }
            int m = s + (e - s)/2;
            mini = min(mini, nums[m]);
            if(nums[s] <= nums[m]){
                s = m + 1;
            }
            else{
                e = m - 1;
            }
        }
        return mini;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << s.findMin(nums) << endl;
    return 0;
}