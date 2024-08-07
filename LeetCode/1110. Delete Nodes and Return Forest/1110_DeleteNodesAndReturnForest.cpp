#include<iostream>
#include<vector>
#include<unordered_set>
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;

        //store every element we have to delete in a set
        unordered_set<int> st;
        for(int &num : to_delete){
            st.insert(num);
        }

        deleteHelper(root, st, result);

        if(st.find(root->val) == st.end()){         //we check if the root itself is in to_delete or notw
            result.push_back(root);
        }
        return result;
    }
private:
    TreeNode* deleteHelper(TreeNode* root, unordered_set<int> st, vector<TreeNode*>& result){
        if(root == NULL) return NULL;

        //going to bottom 
        root->left = deleteHelper( root->left, st, result);     //going to left bottom
        root->right = deleteHelper( root->right, st, result);   //going to right bottom

        if(st.find(root->val) != st.end()){ //if the value of root is present is set
            if(root->left != NULL){
                result.push_back(root->left);
            }
            if(root->right != NULL){
                result.push_back(root->right);
            }

            return NULL;    //now delete
        }
        else{
            return root;
        }
    }
};

int main(){
    Solution obj;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<int> to_delete = {3, 5};
    vector<TreeNode*> result = obj.delNodes(root, to_delete);

    for(auto node : result){
        cout << node->val << " ";
    }
    return 0;
}