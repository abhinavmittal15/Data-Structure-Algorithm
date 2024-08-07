#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;    

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int expectedNum = 1;
        while (numSet.find(expectedNum) != numSet.end()) {
            expectedNum++;
        }
        return expectedNum;
    }
};
int main(){
    Solution solution;
    vector<int> nums = {3, 4, -1, 1};
    cout << solution.firstMissingPositive(nums) << endl;
    return 0;
}