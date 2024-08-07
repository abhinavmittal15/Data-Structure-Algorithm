#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums){
        int i = 0;
        for(int j=0; j<nums.size(); j++){
            if(nums[j] != 0){
                swap(nums[j] , nums[i]);
                i++;
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,1,0,3,12};
    s.moveZeroes(nums);
    for(auto i : nums)
        cout << i << " ";
    cout<< endl;
    return 0;
}