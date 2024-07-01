#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                count++;
            }
            else{
                count = 0;
            }          
            maxi = max(maxi, count);  
        }
        return maxi;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << s.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}