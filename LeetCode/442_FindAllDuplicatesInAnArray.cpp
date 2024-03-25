#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    vector<int> findDuplicates(vector<int>& nums){

        unordered_map<int, int> counts;
        vector<int> res;
        
        for(int i : nums){
            counts[i]++;
            if(counts[i] == 2){
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution s;
    vector<int> res = s.findDuplicates(nums);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}