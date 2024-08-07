#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums){
        int count = 0;
        int n = nums.size();

        for(int i = 1; i <n ; i++){
            if(nums[i-1] > nums[i])
                count++;
        }

        if(nums[n-1] > nums[0])
            count++;
        
        return count<=1;    
    }
};

int main(){
    Solution S;
    vector<int> nums = {2,3,5,1,2};
    cout<<S.check(nums)<<endl;
    return 0;
}