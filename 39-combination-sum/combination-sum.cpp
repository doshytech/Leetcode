class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        f({},0,candidates,target);
        return ans;
    }
    void f(vector<int> tk, int i, vector<int> &v,int t){
        if(i==v.size()){
            if(t==0)ans.push_back(tk);
            return;
        }
        f(tk,i+1,v,t);
        if(v[i]<=t){
            tk.push_back(v[i]);
            f(tk,i,v,t-v[i]);
        }
    }
};