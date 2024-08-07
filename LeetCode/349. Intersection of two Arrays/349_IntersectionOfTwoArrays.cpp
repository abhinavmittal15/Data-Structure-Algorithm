#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> intersection;
        for(int num : nums2){
            if(set.count(num)){
                intersection.push_back(num);
                set.erase(num); // Remove the number from the set to avoid duplicates in the result
            }
        }
        return intersection;
    }
};

int main(){
    Solution solution;
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> intersection = solution.intersection(nums1, nums2);
    for(int num : intersection){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}