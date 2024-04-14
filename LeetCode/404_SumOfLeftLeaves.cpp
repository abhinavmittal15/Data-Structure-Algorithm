#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
};

TreeNode* createNode(int value) {
    return new TreeNode(value);
}

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)  return 0;
        int sum = 0;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            sum += root->left->val;
        }
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};


int main()
{
    TreeNode * root = NULL;
    root = createNode(3);
    root -> left = createNode(9);
    root -> right = createNode(20);
    root -> right -> left = createNode(15);
    root -> right -> right = createNode(7);
    Solution s;
    int sum = s.sumOfLeftLeaves(root);
    cout << sum << endl;
}