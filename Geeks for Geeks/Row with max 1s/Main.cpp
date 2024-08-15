#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int r = 0;
        int c = m -1;
        int rowIndex = -1;
        
        while(r < n && c >= 0){
            if(arr[r][c] == 1){
                rowIndex = r;
                c--;
            }
            else{
                r++;
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