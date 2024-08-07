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
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        DFS(root, moves);
        return moves;
    }
private:
    int DFS(TreeNode* root, int& moves){
        if(root == nullptr)
            return 0;
        
        int left = DFS(root->left, moves);
        int right = DFS(root->right, moves);

        moves = moves + abs(left) + abs(right);
        return root->val + left + right - 1;
    }
};

int main(){
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
    cout << s.distributeCoins(root) << endl;
    return 0;
}