#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int maxCount = 0;
        int rowIndex = -1;

        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<m; j++){
                if(arr[i][j] == 1){
                    count++;
                }
            }
            if(count > maxCount){
                maxCount = count;
                rowIndex = i;
            }
        }
        return rowIndex;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> arr = {{0, 1, 1, 1},{0, 0, 1, 1},{1, 1, 1, 1},{0, 0, 0, 0}};
    cout << obj.rowWithMax1s(arr) << endl;
    return 0;
}