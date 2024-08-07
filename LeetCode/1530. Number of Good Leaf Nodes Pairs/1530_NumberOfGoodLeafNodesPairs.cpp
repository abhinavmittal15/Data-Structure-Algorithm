#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        help(distance, root, ans);
        return ans;
    }
private:
    vector<int> help(int d, TreeNode* root, int& ans) {
        if (!root) return vector<int>(d + 1, 0); // Correct base case for null nodes
        if (!root->left && !root->right) {
            vector<int> leafDist(d + 1, 0);
            leafDist[1] = 1; // Correct representation for a leaf node
            return leafDist;
        }

        auto left = help(d, root->left, ans);
        auto right = help(d, root->right, ans);

        // Correct logic for counting pairs
        for (int i = 1; i <= d; i++) {
            for (int j = 1; j <= d; j++) {
                if (i + j <= d) {
                    ans += left[i] * right[j];
                }
            }
        }

        vector<int> res(d + 1, 0); // Correctly updating distances for parent nodes
        for (int i = 1; i < d; i++) { // Only go up to d-1 to avoid exceeding the distance limit
            res[i + 1] = left[i] + right[i];
        }

        return res;
    }
};