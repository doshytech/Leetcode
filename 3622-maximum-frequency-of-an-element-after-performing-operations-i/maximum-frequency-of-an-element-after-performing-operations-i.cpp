class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mx = *max_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        for(auto &x: nums)mp[x]++;
        int ans = 0;
        for(int i=1;i<=mx;i++){
            auto it = upper_bound(nums.begin(),nums.end(),i+k);
            auto bt = lower_bound(nums.begin(),nums.end(),i-k);
            ans = max(ans,min(numOperations,int(it-bt)-mp[i])+mp[i]);
        }
        return ans;
    }
};