#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        while(s <= e){
            int m = s + (e - s)/2;
            if(nums[m] == target){
                return m;
            }
            else if(nums[m] > target){
                e = m - 1;
            }
            else{
                s = m + 1;
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << sol.search(nums, target) << endl;
    return 0;
}