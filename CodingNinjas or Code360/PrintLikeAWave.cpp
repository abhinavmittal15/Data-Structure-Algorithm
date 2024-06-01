#include <bits/stdc++.h> 

using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for(int col = 0; col < mCols; col++){
        if(col&1){
            //its odd -> bottom to up
            for(int row = nRows - 1; row >=0 ; row--){
                ans.push_back(arr[row][col]);
            }
        }
        else{
            //its even -> top to bottom
            for(int row = 0 ; row < nRows ; row++){
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int> result = wavePrint(arr, 4, 4);
    for(int num : result){
        cout << num << " ";
    }
    return 0;
}