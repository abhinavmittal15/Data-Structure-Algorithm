#include<iostream>
#include<vector>
#include<numeric>
#include<functional>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        const int xors = accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
        return __builtin_popcount(k ^ xors);
    } 
};

int main(){
    Solution s;
    vector<int> nums = {2,1,3,4};
    int k = 1;
    cout << s.minOperations(nums, k) << endl;
    return 0;
}