#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=1; j<nums.size(); j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}