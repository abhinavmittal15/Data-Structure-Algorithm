#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        unordered_map<int, int> remainderMap;

        remainderMap[0] = -1; // Handle case where subarray starts from index 0

        int runningSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            if (k != 0) {
                runningSum %= k;
            }

            if (remainderMap.find(runningSum) != remainderMap.end()) {
                if (i - remainderMap[runningSum] > 1) {
                    return true;
                }
            } 
            else {
                remainderMap[runningSum] = i;
            }
        }

        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;
    cout << s.checkSubarraySum(nums, k) << endl;
    return 0;
}