#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    int atMostK(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> freq;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (freq[nums[right]]++ == 0) {
                k--;
            }

            while (k < 0) {
                if (--freq[nums[left]] == 0) {
                    k++;
                }
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << sol.subarraysWithKDistinct(nums, k) << endl;
    return 0;
}