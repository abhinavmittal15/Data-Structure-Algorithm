#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n-2, vector<int>(n-2));
        for(int i=0; i < n-2; i++){
            for(int j=0 ; j < n -2 ; j++){
                maxLocal[i][j] = findMax(grid, i , j);
            }
        }
        return maxLocal;
    }
private:
    int findMax(vector<vector<int>>& grid, int i, int j){
        int maxa = INT_MIN;
        for(int x=i; x<i+3; x++){
            for(int y=j ; y<j+3; y++){
                maxa = max(maxa, grid[x][y]);
            }
        }
        return maxa;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{9, 9 ,8, 1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
    vector<vector<int>> res = s.largestLocal(grid);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}