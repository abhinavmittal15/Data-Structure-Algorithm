#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        bool currState = true;              //true represent 1, false represent 0
        for(int i=0; i<nums.size(); i++){
            if((nums[i] == 1) != currState){
                ans++;
                currState = !currState;     // flip the state (i.e. 1 -> 0 or 0 -> 1)
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0, 1, 1, 0, 1};
    cout << sol.minOperations(nums) << endl;
    return 0;
}