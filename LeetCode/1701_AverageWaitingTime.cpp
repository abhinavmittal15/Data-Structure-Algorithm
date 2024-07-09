#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double ans = 0;
        int customerTime = 0;
        int time = customers[0][0];
        for(int i=0; i<n; i++){
            time = max(time, customers[i][0]);
            time = time + customers[i][1];
            customerTime = time - customers[i][0];
            ans = ans + customerTime;
        }
        return ans / n;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> customers = {{1, 2}, {2, 5}, {4, 3}};
    cout << fixed << setprecision(5) << sol.averageWaitingTime(customers) << endl;
    return 0;
}