#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
        unordered_map<int, int> freqMap;
        int maxCount = 0, count = 0;

        for(int num : nums) {
            int freq = ++freqMap[num];
            if (freq > maxCount) {
                maxCount = freq;
                count = freq;
            } else if (freq == maxCount) {
                count += freq;
            }
        }
        return count;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {1, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    std::cout << solution.maxFrequencyElements(nums) << std::endl;
    return 0;
}