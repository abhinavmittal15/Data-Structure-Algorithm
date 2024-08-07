#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        
        int prod = 1;
        int ans = 0;
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            prod = prod * nums[right];
            while(prod >= k)
                prod = prod / nums[left++];
            
            ans = ans + right - left + 1;
        }
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout<<obj.numSubarrayProductLessThanK(nums, k);
    return 0;
}