#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> count;
        count[0] =  1;
        int sum = 0;
        int result = 0;
        for(int i : nums){
            sum = sum + i;
            result = result + count[sum - goal];
            count[sum]++;
        }
        return result;
    }
};



int main(){
    Solution s;
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    cout<<s.numSubarraysWithSum(nums, goal)<<endl;
    return 0;
}