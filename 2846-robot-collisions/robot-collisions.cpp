class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        vector<vector<int>> v;
        int n = h.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            v.push_back({p[i],h[i],(d[i]=='R'?1:-1)});
            mp[p[i]]=i;
        }
        sort(v.begin(),v.end());
        stack<vector<int>> stk;
        for(auto &x: v){
            int hi = x[1], dr = x[2];
            bool val = false;
            while(stk.size()&&stk.top()[2]>dr){
                if(val)break;
                if(stk.top()[1]<hi){
                    hi--;
                    stk.pop();
                }
                else if(stk.top()[1]==hi){
                    stk.pop();
                    val = true;
                }
                else{
                    vector<int> vt = stk.top();
                    stk.pop();
                    stk.push({vt[0],vt[1]-1,vt[2]});
                    val = true;
                }
            }
            if(!val)stk.push({x[0],hi,dr});
        }
        vector<int> ans(n);
        while(stk.size()){
            // ans.push_back(stk.top()[0]);
            int i = stk.top()[0];
            ans[mp[i]]=stk.top()[1];
            stk.pop();
        }
        vector<int> pt;
        for(auto &x: ans){
            if(x)pt.push_back(x);
        }
        return pt;
    }
};