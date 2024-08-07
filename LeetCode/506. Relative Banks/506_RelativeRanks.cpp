#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>sc = score;
        sort(sc.begin(), sc.end(), greater<int>());
        
        map<int, string> count;
        for(int i=0; i<sc.size(); i++){
            if(i==0){
                count[sc[i]] = "Gold Medal";
            }
            else if(i==1){
                count[sc[i]] = "Silver Medal";
            }
            else if(i==2){
                count[sc[i]] = "Bronze Medal";
            }
            else{
                count[sc[i]] = to_string(i+1);
            }
            
        }
        vector<string> result;
        for(int i=0; i<score.size(); i++){
            result.push_back(count[score[i]]);
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> score = {10,3,8,9,4};
    vector<string> result = s.findRelativeRanks(score);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}