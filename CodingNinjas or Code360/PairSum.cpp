// Link : https://www.naukri.com/code360/problems/pair-sum_697295

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
    vector<vector<int>> result;
    for (int i = 0; i < arr.size(); i++){
        for (int j = i + 1; j < arr.size(); j++){
            if (arr[i] + arr[j] == s){
                int first = min(arr[i], arr[j]);
                int second = max(arr[i], arr[j]);
                result.push_back({first, second});
            }
        }
    }
    sort(result.begin(), result.end(), [](const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) return a[1] < b[1]; // If first elements are equal, sort by second
        return a[0] < b[0]; // Otherwise, sort by first element
    });
    return result;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int s = 5;
    vector<vector<int>> ans = pairSum(arr, s);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}