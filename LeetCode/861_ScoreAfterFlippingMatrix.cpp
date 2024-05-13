#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        // Flip the row
        for(int r=0 ; r < row ; r++){
            if(grid[r][0] == 0){
                for(int c=0; c < col ; c++){
                    if(grid[r][c] == 1){
                        grid[r][c] = 0;
                    }
                    else{
                        grid[r][c] = 1;
                    }
                }
            }
        }

        //Flip the column
        for(int c=0 ; c < col ; c++){
            int count_ones = 0;
            for(int r=0 ; r < row ; r++){
                if(grid[r][c] == 1){
                    count_ones++;
                }
            }
            int count_zeroes = row - count_ones;
            if(count_ones < count_zeroes){
                for(int r=0 ; r < row ; r++){
                    if(grid[r][c] == 1){
                        grid[r][c] = 0;
                    }
                    else{
                        grid[r][c] = 1;
                    }
                }
            }
        }

        int res = 0;
        for(int r=0 ; r < row ; r++){
            for(int c=0 ; c < col ; c++){
                if(grid[r][c] == 1){
                    res += pow(2, col - c - 1);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    cout << s.matrixScore(grid) << endl;
    return 0;
}