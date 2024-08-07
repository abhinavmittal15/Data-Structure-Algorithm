#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        int decremented = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for(int i=0; i<k; i++){
            ans = ans + max(0, happiness[i] - decremented);
            decremented++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> happiness = {1, 2, 3};
    int k = 2;
    cout<< s.maximumHappinessSum(happiness, k) << endl;
    return 0;
}