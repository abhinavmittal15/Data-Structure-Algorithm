#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// class Solution {
// public:
//     int missingNumber(vector<int>& nums){
//         for(int i=0; i<nums.size() + 1; i++){
//             if(find(nums.begin(), nums.end(), i) == nums.end()){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

// or

//here we used sum of natural numbers technique instead of using function like find() in above approach
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n+1) /2; //sum of n natural numbers
        int sum = 0;
        for(int i : nums){
            sum += i;
        }
        return total - sum;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3, 0, 1};
    cout << s.missingNumber(nums) << endl;
    return 0;
}