#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
    public:
    int findMaxLength(vector<int>& nums){
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0; 
        int maxLen = 0;
        for(int i=0; i<nums.size(); i++){
            sum += (nums[i] == 1) ? 1 : -1;
            if(mp.count(sum)){
                maxLen = max(maxLen, i - mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }       
        return maxLen;
    }
};

int main(){
    Solution s;
    vector<int> nums = {0, 1, 0};
    cout << s.findMaxLength(nums) << endl;
    return 0;
}