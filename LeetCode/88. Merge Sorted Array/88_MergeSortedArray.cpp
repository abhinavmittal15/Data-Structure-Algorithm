#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){

        vector<int> nums3;
        int i = 0, j = 0;
        while (i < m && j < n){
            if (nums1[i] < nums2[j]){
                nums3.push_back(nums1[i]);
                i++;
            }
            else{
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m){
            nums3.push_back(nums1[i]);
            i++;
        }
        while( j < n){
            nums3.push_back(nums2[j]);
            j++;
        }
        nums1 = nums3;
    }
};


int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;

    Solution S;

    S.merge(nums1, m, nums2, n);

    for(auto i : nums1) 
        cout << i <<" ";
    
    return 0;
}