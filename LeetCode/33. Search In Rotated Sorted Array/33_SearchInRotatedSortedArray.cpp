#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s <= e){
            int m = s + (e-s)/2;
            if(nums[m] == target){
                return m;
            }
            // if terget is not at mid then check for which part is sorted left || right
            if(nums[s] <= nums[m]){
                //left part is sorted
                if(nums[s] <= target && target <= nums[m]){
                    //means target lies in left part, so eliminate right part
                    e = m - 1;
                }
                else{
                    //target doesn't lie in left part, so eliminate left part
                    s = m + 1;
                }
            }
            else{
                //right part is sorted
                if(nums[m] <= target && target <= nums[e]){
                    //means target lies in right part, so eliminate left part
                    s = m + 1;
                }
                else{
                    //target doesn't lie in right part, so eliminate right part
                    e = m - 1;
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << s.search(nums, target) << endl;
    return 0;
}