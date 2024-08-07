#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int minOperations(vector<int>& nums){
        int ans = 0;
        for(int i=0; i<nums.size()-2; i++){
            if(nums[i] == 0){
                nums[i] = 1;
                nums[i+1] = nums[i+1] == 0 ? 1 : 0; // if nums[i+1] is 0, make it 1, else make it 0 and return the result to nums[i+1]
                nums[i+2] = nums[i+2] == 0 ? 1 : 0; // if nums[i+2] is 0, make it 1, else make it 0 and return the result to nums[i+2]
                ans++;
            }
        }
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0){ //if still there is a 0 present 
                return -1;    // then return -1
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0, 1, 1, 1, 0, 0};
    cout << sol.minOperations(nums) << endl;
    return 0;
}