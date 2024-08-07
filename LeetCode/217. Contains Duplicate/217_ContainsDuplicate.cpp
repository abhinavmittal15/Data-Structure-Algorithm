#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i =0; i<nums.size() -1; i++){
            if(nums[i]  == nums[i+1]){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,1};
    cout << s.containsDuplicate(nums) << endl;
    return 0;
}