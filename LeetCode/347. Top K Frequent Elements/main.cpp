#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++) {
            map[nums[i]]++;
        }
        priority_queue<pair<int, int>> maxHeap;
        for(const auto& pair : map) {
            maxHeap.push({pair.second, pair.first});
        }
        vector<int> result;
        for(int i=0; i<k&& !maxHeap.empty(); i++) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = obj.topKFrequent(nums, k);
    for(int res : result) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}