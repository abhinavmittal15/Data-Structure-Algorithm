#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderCount;
        remainderCount[0] = 1;
        int prefixSum = 0;
        int ans = 0;
        for(auto num : nums){
            prefixSum += num;
            int remainder = (prefixSum % k + k) % k;

            if(remainderCount .find(remainder) != remainderCount.end()){
                ans += remainderCount[remainder];
            }
            remainderCount[remainder]++; 
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    cout << s.subarraysDivByK(nums, k) << endl;
    return 0;
}