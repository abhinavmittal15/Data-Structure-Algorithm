#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int row = grid.size(); 
        int col = grid[0].size();
        int res = 0;
        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                res = max(res,  DFS(grid, r, c));
            }
        }
        return res;
    }
private:
    int DFS(vector<vector<int>>& grid, int r, int c){
        int row = grid.size(); 
        int col = grid[0].size();
        if(min(r, c) < 0 || r == row || c == col || grid[r][c] == 0)
            return 0;
            
        int tmp = grid[r][c];
        grid[r][c] = 0;
        int res = 0;
        vector<pair<int, int>> neighbour = {{r+1, c}, {r-1, c}, {r, c+1}, {r, c-1}};
        for(auto& n : neighbour)
            res = max(res, tmp + DFS(grid, n.first, n.second));

        grid[r][c] = tmp;
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
    cout << sol.getMaximumGold(grid) << endl;
    return 0;   
}