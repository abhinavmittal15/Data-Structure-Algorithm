#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(std::vector<int>& nums, int k) {
        int size = nums.size(); // Store the size of the input vector nums
        vector<int> count(size + 1, 0); // Vector to store the count of odd numbers
        count[0] = 1; // There's one way to have zero odd numbers - empty subarray

        int answer = 0; // Initialize the count of valid subarrays
        int oddCount = 0; // Counter for the number of odd numbers in the current sequence

        // Iterate through the input numbers
        for (int num : nums) {
            oddCount += num & 1; // Increment the odd count if num is odd
            // If there have been at least k odd numbers so far, update the answer
            if (oddCount >= k) {
                answer += count[oddCount - k];
            }
            count[oddCount]++; // Increment the count for this number of odd numbers
        }
        return answer; // Return the total number of valid subarrays
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    cout << s.numberOfSubarrays(nums, k) << endl;
    return 0;
}