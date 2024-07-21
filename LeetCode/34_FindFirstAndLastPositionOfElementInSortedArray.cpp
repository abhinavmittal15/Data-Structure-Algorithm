#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        vector<int> ans;
        while(s <= e){
            int m = s + (e-s)/2;
            if(nums[m] == target){
                ans.push_back(m);
                if(nums[m+1] == nums[m]){
                    ans.push_back(m+1);
                }
                else if(nums[m-1] == nums[m]){
                    ans.push_back(m-1);
                }
            }
            else if(nums[m] < target){
                s = m + 1;
            }
            else{
                e = m - 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> ans = s.searchRange(nums, target);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}