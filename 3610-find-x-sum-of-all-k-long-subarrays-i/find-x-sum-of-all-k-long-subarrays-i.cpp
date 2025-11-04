class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n-k+1;i++){
            vector<int> ct(51);
            int sm = 0;
            for(int j=i;j<i+k;j++){
                ct[nums[j]]++;
            }
            // map<int,int> freq;
            vector<pair<int,int>> vt;
            for(int j=1;j<=50;j++){
                if(ct[j]){
                    vt.push_back({ct[j],j});
                }
            }
            sort(vt.rbegin(),vt.rend());
            // vector<int> toc;
            // for(auto &x: freq)toc.push_back(x.second);
            // reverse(toc.begin(),toc.end());
            for(int j=0;j<min(x,(int)vt.size());j++){
                sm+=vt[j].second*vt[j].first;
            }
            // for(auto &x: vt)cout<<x.first<<" "<<x.second<<endl;;
            // cout<<endl;
            ans.push_back(sm);
        }
        return ans;
    }    
};