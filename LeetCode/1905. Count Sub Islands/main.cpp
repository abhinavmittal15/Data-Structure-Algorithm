#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        for(int i=0; i<grid2.size(); i++) {
            for(int j=0; j<grid2[0].size(); j++) {
                int flag = 1;
                if(grid2[i][j] == 1) {
                    function(grid1, grid2, i, j, flag);
                    if(flag == 1) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
private:
    void function(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int& flag) {
        if(i<0 || j<0 || i>=grid2.size() || j>=grid2.size()) {
            return;
        }
        if(grid2[i][j] == 0) {
            return;
        }
        if(grid2[i][j] == 1) {
            if(grid1[i][j] == 0) {
                flag = 0;
                return;
            }
            grid2[i][j] = 0;
        }
        function(grid1, grid2, i-1, j, flag);
        function(grid1, grid2, i+1, j, flag);
        function(grid1, grid2, i, j-1, flag);
        function(grid1, grid2, i, j+1, flag);
    }
};

int main() {
    Solution obj;
    vector<vector<int>> grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
    vector<vector<int>> grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
    cout << obj.countSubIslands(grid1, grid2) << endl;
    return 0;
}