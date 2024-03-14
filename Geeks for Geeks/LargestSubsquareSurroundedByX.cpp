// The link to the problem :- https://www.geeksforgeeks.org/problems/largest-subsquare-surrounded-by-x0558/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
    int largestSubsquare(int n, vector<vector<char>> a){
        vector<vector<int>> psR(n, vector<int>(n, 0));
        vector<vector<int>> psC(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            for(int j =0; j<n ;j++){
                //rows
                 psR[i][j] = (a[i][j] == 'X' ? (j == 0 ? 1 : psR[i][j - 1] + 1) : 0);

                //col
                psC[j][i] = (a[j][i] == 'X' ? (j == 0 ? 1 : psC[j - 1][i] + 1) : 0);
            }
        }
        int max=0;
        for(int i =n-1; i>=0; i--){
            for(int j =n-1; j>=0; j--){
                int size = min(psR[i][j], psC[i][j]);
                    while(size > max){
                        if(psR[i - size +1][j]>=size && psC[i][j-size+1] >=size){
                            max = size; //max size possible
                            break;
                        }
                        else{
                            size--;
                        } //check for smalller size of poss
                    }
            }
        }
        return max;
    }
};

int main(){
    Solution s;
    int n = 4;
    vector<vector<char>> a = {{'X', 'X', 'X', 'O'}, {'X', 'O', 'X', 'X'}, {'X', 'X', 'X', 'O'}, {'X', 'X', 'X', 'X'}};
    cout<<s.largestSubsquare(n, a)<<endl;
    return 0;
}