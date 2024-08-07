#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> countMap;
        for (int i = 0; i < nums.size(); i++) {
            countMap[nums[i]]++;
        }
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (countMap[nums[i]] == 1) {
                nums[index++] = nums[i];
            }
        }
        nums.resize(index);
        return nums;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,1,3,2,5};
    vector<int> result =  sol.singleNumber(nums);
    for(int num : result){
        cout << num << " ";
    }
    return 0;
}