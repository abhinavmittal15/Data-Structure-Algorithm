#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = row*col - 1;

        int mid = start + (end-start)/2;

        while(start <= end){
            int element = matrix[mid/col][mid%col];

            if(element == target){
                return 1;
            }
            if(element < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return 0;
    }
};

int main(){
    Solution s;
    
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;

    cout << s.searchMatrix(matrix, target) << endl;
    return 0;
}