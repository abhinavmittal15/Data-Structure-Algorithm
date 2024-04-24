#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:

    void dfs(vector<vector<int>> &land, int i, int j, int &x, int &y){
        if (i < 0 || i == land.size() || j < 0 || j == land[0].size())
            return;

        if (land[i][j] != 1)
            return;

        land[i][j] = 2; // Mark as visited.
        x = max(x, i);
        y = max(y, j);
        dfs(land, i + 1, j, x, y);
        dfs(land, i, j + 1, x, y);
    }

    vector<vector<int>> findFarmland(vector<vector<int>> &land)    {

        vector<vector<int>> ans;

        for (int i = 0; i < land.size(); ++i)
            for (int j = 0; j < land[0].size(); ++j)
                if (land[i][j] == 1){
                    int x = i;
                    int y = j;
                    dfs(land, i, j, x, y);
                    ans.push_back({i, j, x, y});
                }
        return ans;
    }  
};

int main()
{
    Solution sol;
    vector<vector<int>> land = {{1, 0, 0}, {0, 1, 1}, {0, 1, 1}};
    vector<vector<int>> ans = sol.findFarmland(land);

    for (auto &farmland : ans)
    {
        for (int &coord : farmland)
            cout << coord << " ";
        cout << endl;
    }

    return 0;
}