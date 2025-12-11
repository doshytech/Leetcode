class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int,vector<int>> x, y;
        for(auto &z: buildings){
            x[z[0]].push_back(z[1]);
            y[z[1]].push_back(z[0]);
        }
        for(auto &z: x)sort(z.second.begin(),z.second.end());
        for(auto &z: y)sort(z.second.begin(),z.second.end());
        // for(auto &z: x){
        //     cout<<z.first<<":";
        //     for(auto &p: z.second)cout<<p<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
        // for(auto &z: y){
        //     cout<<z.first<<":";
        //     for(auto &p: z.second)cout<<p<<" ";
        //     cout<<endl;
        // }
        int ct = 0;
        for(auto &z: buildings){
            int n = x[z[0]].size(), m = y[z[1]].size();
            int i = upper_bound(x[z[0]].begin(),x[z[0]].end(), z[1])-x[z[0]].begin();
            int j = upper_bound(y[z[1]].begin(),y[z[1]].end(), z[0])-y[z[1]].begin();
            if(i>1&&n-i>0&&j>1&&m-j>0){
                ct++;
                // cout<<z[0]<<" "<<z[1]<<endl;
            }
        }
        return ct;
    }
};