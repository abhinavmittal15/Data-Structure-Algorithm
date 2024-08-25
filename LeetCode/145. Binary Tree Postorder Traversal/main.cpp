#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
private:
    void dfs(TreeNode* root, vector<int>& result) {
        if(root == nullptr) {
            return;
        }
        dfs(root->left, result);
        dfs(root->right, result);
        result.push_back(root->val);
    }
};

int main() {
    Solution obj;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = obj.postorderTraversal(root);
    for(int res : result) {
        cout << res << " ";
    }
    cout << endl;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}