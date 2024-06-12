#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    void sortColors(vector<int>& nums){
        for(int i=0; i<nums.size(); i++){
            for(int j=nums.size()-1; j>=i; j--){
                if(nums[i] > nums[j]){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    s.sortColors(nums);
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}