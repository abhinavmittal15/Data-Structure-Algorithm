#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        
        unordered_map<int, int> rankMap;
        int rank = 1;
        for(int i : temp) {
            if(rankMap.find(i) == rankMap.end()) {
                rankMap[i] = rank++;
            }
        }
        
        vector<int> res;
        for(int i=0; i<arr.size(); i++) {
            res.push_back(rankMap[arr[i]]);
        }
        return res;
    }
};

int main() {
    Solution obj;
    // vector<int> arr = {40, 10, 20, 30};
    vector<int> arr = {37,12,28,9,100,56,80,5,12};
    vector<int> res = obj.arrayRankTransform(arr);
    for(int i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}