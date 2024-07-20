#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int ans = n;
        while(s <= e){
            int m = s + (e-s)/2;
            if(nums[m] == target){
                return m;
            }
            else if(nums[m] > target) {
                e = m - 1;
                ans = m;
            } 
            else{
                s = m + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;
    cout << s.searchInsert(nums, target) << endl;
    return 0;
}