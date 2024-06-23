#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> window;           //multiset is used bcoz it altomatically keeps the elements in sorted order allowing efficient retreival of mininmum and maximum elements
        int left = 0;
        int maxLength = 0;

        for(int right = 0; right < nums.size(); right ++){
            window.insert(nums[right]); //add curr element to window


            //here we check if the curr window is valid
            while(*window.rbegin() - *window.begin()  >   limit){   //last element - first elemnt > limit
                //if not valid, remove leftmost element and move to left pointer
                window.erase(window.find(nums[left++]));
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

int main(){
    Solution s;
    vector<int> nums = {8, 2, 4, 7};
    int limit = 4;
    cout << s.longestSubarray(nums, limit) << endl;
    return 0;
}