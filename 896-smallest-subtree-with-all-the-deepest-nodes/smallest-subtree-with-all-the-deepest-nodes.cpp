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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<vector<TreeNode*>> v;
        queue<pair<int,TreeNode*>> q;
        map<TreeNode*,vector<TreeNode*>> g;
        map<TreeNode*,int> l;
        q.push({0,root});
        while(q.size()){
            pair<int,TreeNode*> pr = q.front();
            q.pop();
            l[pr.second]=pr.first;
            if(v.size()==pr.first){
                v.push_back({});
            }
            v[pr.first].push_back(pr.second);
            if(pr.second->left!=NULL){
                q.push({pr.first+1,pr.second->left});
                g[pr.second].push_back(pr.second->left);
                g[pr.second->left].push_back(pr.second);
            }
            if(pr.second->right!=NULL){
                q.push({pr.first+1,pr.second->right});
                g[pr.second].push_back(pr.second->right);
                g[pr.second->right].push_back(pr.second);
            }
        }
        if(v.back().size()==1)return v.back()[0];
        TreeNode* ans = v.back()[0];
        for(int i=0;i<v.back().size()-1;i++){
            for(int j=i+1;j<v.back().size();j++){
                vector<TreeNode*> path;
                dfs(v.back()[i],g,path,v.back()[j]);
                for(auto &x: path){
                    if(l[x]<l[ans]){
                        ans = x;
                    }
                }
            }
        }
        return ans;
    }
    void dfs(TreeNode* v, map<TreeNode*,vector<TreeNode*>> &g, vector<TreeNode*> &path, TreeNode* &dest,TreeNode* par=NULL){
        for(auto &x: g[v]){
            if(x==par)continue;
            dfs(x,g,path,dest,v);    
        }
        if(path.size()||v==dest){
            path.push_back(v);
        }
    }
};