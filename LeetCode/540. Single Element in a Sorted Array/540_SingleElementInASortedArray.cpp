#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(nums[0] != nums[1]){
            return nums[0];
        }
        if(nums[n-1] != nums[n-2]){
            return nums[n-1];
        }
        int s = 1;
        int e = n-2;
        while(s <= e){
            int m = s + (e-s)/2;
            if(nums[m] != nums[m-1] && nums[m] != nums[m+1]){
                return nums[m];
            }
            if(((m%2 == 1) && nums[m] == nums[m-1]) || ((m%2 == 0) && nums[m] == nums[m+1])){
                s = m + 1;
            }
            else{
                e = m - 1;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout<< s.singleNonDuplicate(nums) << endl;
    return 0;
}