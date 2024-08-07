#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        for (const vector<int> &row : matrix)
        {
            const int minIndex = distance(row.begin(), ranges::min_element(row));
            if (row[minIndex] == maxNumOfColumn(matrix, minIndex))
                return {row[minIndex]};
        }
        return {};
    }

private:
    int maxNumOfColumn(const vector<vector<int>> &matrix, int j)
    {
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i)
            res = max(res, matrix[i][j]);
        return res;
    }
};

// class Solution {
// public:
//     vector<int> luckyNumbers (vector<vector<int>>& matrix) {
//         vector<int> res;
//         int maxi = 0;
//         for(int i=0; i<matrix.size(); i++){
//             int minRow = matrix[i][0];
//             int colIndex = 0;
//             for(int j = 1; j<matrix[i].size(); j++){
//                 if(matrix[i][j] < minRow){
//                     minRow = matrix[i][j];
//                     colIndex = j;
//                 }
//             }
//             bool isLucky = true;
//             for(int k = 0; k<matrix[i].size(); k++){
//                 if(matrix[k][colIndex] > minRow){
//                     isLucky = false;
//                     break;
//                 }
            
//             }
//             if(isLucky){
//                 res.push_back(minRow);
//             }
//         }
//         return res;
//     }
// };


int main(){
    Solution sol;
    vector<vector<int>> matrix = {{3,7,8},{9,11,13},{15,16,17}};
    
    vector<int> res = sol.luckyNumbers(matrix);
    
    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}