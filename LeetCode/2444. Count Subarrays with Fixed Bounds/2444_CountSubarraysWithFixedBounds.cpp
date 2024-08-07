#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ans = 0;
        int j = -1;
        int prevMinKIndex = -1;
        int prevMaxKIndex = -1;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < minK || nums[i] > maxK)
                j = i;
            if (nums[i] == minK)
                prevMinKIndex = i;
            if (nums[i] == maxK)
                prevMaxKIndex = i;
            // Any index k in [j + 1, min(prevMinKIndex, prevMaxKIndex)] can be the
            // start of the subarray s.t. nums[k..i] satisfies the conditions.
            ans += max(0, min(prevMinKIndex, prevMaxKIndex) - j);
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,5,2,7,5};
    int minK = 1;
    int maxK = 5;
    cout << s.countSubarrays(nums, minK, maxK) << endl;
    return 0;
}