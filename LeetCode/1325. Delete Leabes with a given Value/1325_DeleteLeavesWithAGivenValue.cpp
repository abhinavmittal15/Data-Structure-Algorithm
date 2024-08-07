#include<iostream>
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == nullptr)
            return nullptr;

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if (isLeaf(root) && root->val == target) {
            return nullptr;
        } else {
            return root;
        }
    }

private:
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
};
