#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        for(int i : nums2){
            if(set.count(i)){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution solution;
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,4};
    cout << solution.getCommon(nums1, nums2) << endl;
    return 0;
}