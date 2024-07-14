#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int profit = 0;
        int maxiProfit = 0;
        for(int i=0; i<prices.size(); i++){
            for(int j=i; j<prices.size(); j++){
                if(prices[i] <= prices[j]){
                    maxi = max(maxi, prices[j]);
                    profit = prices[maxi] - prices[i];
                    maxiProfit = max(maxiProfit, profit);
                }
            }
        }
        return maxiProfit;
    }
};

int main(){
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}