#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>> pq;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                pq.push({-double(arr[i]) / arr[j] , {i, j}});
            }
        }

        for(int i=0; i<k - 1; i++){
            pq.pop();
        }

        auto fraction = pq.top().second;
        return {arr[fraction.first], arr[fraction.second]};
    }
};

int main(){
    Solution s;
    vector<int> arr = {1, 2, 3, 5};
    int k = 3;
    vector<int> result = s.kthSmallestPrimeFraction(arr, k) ;

    for(int i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}