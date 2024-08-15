#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int count = 0;
        int maxi = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == 1){
                    count++;
                }
            }
            maxi = max(maxi, count);
            return i;
        }
        return -1;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> arr = {{0, 1, 1, 1},{0, 0, 1, 1},{1, 1, 1, 1},{0, 0, 0, 0}};
    cout << obj.rowWithMax1s(arr) << endl;
    return 0;
}