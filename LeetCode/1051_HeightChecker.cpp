#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights;
        sort(sortedHeights.begin(), sortedHeights.end());
        int res = 0;
        for(int i=0; i<heights.size(); i++){
            if(heights[i] != sortedHeights[i]){
                res++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> heights = {1, 1, 4, 2, 1, 3};
    cout << s.heightChecker(heights) << endl;
    return 0;
}