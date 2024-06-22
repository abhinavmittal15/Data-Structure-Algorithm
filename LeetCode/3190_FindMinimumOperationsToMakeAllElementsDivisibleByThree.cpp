#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%3 != 0){
                if((nums[i] + 1)%3  == 0 || (nums[i]-1)%3 == 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    cout << s.minimumOperations(nums) << endl;
    return 0;
}