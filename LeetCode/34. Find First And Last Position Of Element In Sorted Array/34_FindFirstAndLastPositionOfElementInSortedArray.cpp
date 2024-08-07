#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums, n, target);
        if(lb == n || nums[lb] != target){
            return {-1, -1};
        }
        int ub = upperBound(nums, n, target);
        return {lb, ub - 1};
    }
private:
    int lowerBound(vector<int> arr, int n, int k){
        int s = 0;
        int e = n-1;
        int ans = n;
        while(s <= e){
            int m = s + (e-s)/2;
            if(arr[m] >= k){
                e = m - 1;
                ans = m;
            }
            else{
                s = m + 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int> arr, int n, int k){
        int s = 0;
        int e = n-1;
        int ans = n;
        while(s <= e){
            int m = s + (e-s)/2;
            if(arr[m] > k){
                e = m - 1;
                ans = m;
            }
            else{
                s = m + 1;
            }
        }
        return ans;
    }

};

int main(){
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> ans = s.searchRange(nums, target);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}