#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
//         answer = [];
//         for(int i=0; i<n; i++){
//             for(int j=i; j<i.size(); j++){
//                 findDistance(edges[i][j]);
//             }
//             answer.push_back()
//         }
//     }
// };

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> tree(n);
        vector<int> res(n, 0), count(n, 0);
        
        // Build the tree from edges
        for (int i = 0; i < edges.size(); i++) {
            tree[edges[i][0]].insert(edges[i][1]);
            tree[edges[i][1]].insert(edges[i][0]);
        }
        
        dfs(0, -1, tree, res, count);
        dfs2(0, -1, tree, res, count, n);
        return res;
    }

private:
    void dfs(int root, int pre, vector<unordered_set<int>>& tree, vector<int>& res, vector<int>& count) {
        for (auto &i : tree[root]) {
            if (i == pre) continue;
            dfs(i, root, tree, res, count);
            count[root] += count[i];
            res[root] += res[i] + count[i];
        }
        count[root] += 1;
    }

    void dfs2(int root, int pre, vector<unordered_set<int>>& tree, vector<int>& res, vector<int>& count, int n) {
        for (auto &i : tree[root]) {
            if (i == pre) continue;
            res[i] = res[root] - count[i] + n - count[i];
            dfs2(i, root, tree, res, count, n);
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{2,4},{2,5}};
    vector<int> res = s.sumOfDistancesInTree(6, edges);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}