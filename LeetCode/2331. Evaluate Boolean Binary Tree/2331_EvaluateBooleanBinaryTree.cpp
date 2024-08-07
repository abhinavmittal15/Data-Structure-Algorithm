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
    bool evaluateTree(TreeNode* root) {
        if(root->left==nullptr && root->right==nullptr){
            if(root->val == 0){
                return false;
            }
            return true;
        }

        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);

        if(root->val == 2){
            return left || right;
        }
        return left && right;
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode();
    root->left->right = new TreeNode();
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    cout << s.evaluateTree(root) << endl;
    return 0;
}