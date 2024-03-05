#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum= 0;
        for(int num : nums){
            totalSum += num;
        }
        int runningSum =0;
        for(int i=0; i<nums.size(); i++){
            if(runningSum  == totalSum - runningSum - nums[i]){
                return i;
            }
            runningSum += nums[i];
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {1,7,3,6,5,6};
    Solution s;
    cout<<s.pivotIndex(nums);
    return 0;
}