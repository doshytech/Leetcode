/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(0,ans,root);
        return ans;
    }
    void dfs(int h, vector<int> &ans, TreeNode* root){
        if(!root)return;
        if(h==ans.size())ans.push_back(root->val);
        dfs(h+1,ans,root->right);
        dfs(h+1,ans,root->left);
    }
};