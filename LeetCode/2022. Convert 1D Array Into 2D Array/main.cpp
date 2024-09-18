#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n) return {};
        vector<vector<int>> result(m, vector<int>(n));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                result[i][j] = original[i*n + j];
            }
        }
        return result;
    }
};

int main() {
    Solution obj;
    vector<int> original = {1, 2, 3, 4};
    int m = 2;
    int n = 2;
    vector<vector<int>> result = obj.construct2DArray(original, m, n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}