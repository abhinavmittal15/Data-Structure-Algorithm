#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> heightNamePairs;
        for(int i=0; i<names.size(); i++){
            heightNamePairs.push_back({heights[i], names[i]});
        }
        sort(heightNamePairs.begin(), heightNamePairs.end(), [](const pair<int, string>& a, const pair<int, string>& b){
            return a.first < b.first;
        });
        
        vector<string> ans;
        for(auto i : heightNamePairs){
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main(){
    Solution obj;
    vector<string> names = {"Mary","John","Emma"};
    vector<int> heights = {180,165,170};
    vector<string> ans = obj.sortPeople(names, heights);
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}