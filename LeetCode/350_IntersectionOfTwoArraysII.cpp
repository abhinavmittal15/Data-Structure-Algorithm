#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> countMap;
        vector<int> result;
        for(int num : nums1)
            countMap[num]++;

        for(int num : nums2){
            if(countMap[num] > 0){
                result.push_back(num);
                countMap[num]--;
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = solution.intersect(nums1, nums2);
    for(int res : result){
        cout << res << " ";
    }
    return 0;
}