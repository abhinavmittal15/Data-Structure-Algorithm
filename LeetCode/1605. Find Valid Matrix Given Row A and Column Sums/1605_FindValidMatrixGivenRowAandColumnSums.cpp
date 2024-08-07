#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();

        vector<vector<int>> matrix(n, vector<int>(m, 0));
        int i=0;
        int j=0;

        while(i < n && j < m){
            matrix[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= matrix[i][j];
            colSum[j] -= matrix[i][j];

            if(rowSum[i]==0) i++;
            if(colSum[j]==0) j++;
        }
        return matrix;
    }
};

int main(){
    Solution obj;
    vector<int> rowSum = {3, 8};
    vector<int> colSum = {4, 7};
    vector<vector<int>> matrix = obj.restoreMatrix(rowSum, colSum);
    for(int i=0; i<rowSum.size(); i++) {
        for(int j=0; j<colSum.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}