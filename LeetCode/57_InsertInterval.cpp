#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        while(i < intervals.size() && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i++]);
        }
        while(i < intervals.size() && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        while(i < intervals.size()){
            res.push_back(intervals[i++]);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};
    vector<vector<int>> res = s.insert(intervals, newInterval);
    for(int i = 0; i < res.size(); i++){
        cout << res[i][0] << " " << res[i][1] << endl;
    }
    return 0;
}