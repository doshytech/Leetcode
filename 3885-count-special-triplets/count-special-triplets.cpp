class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long long sm = 0;
        int mod = 1e9+7;
        map<int,int> pre, post;
        for(auto &x: nums)post[x]++;
        for(auto &x: nums){
            post[x]--;
            sm+=post[2*x]*1LL*pre[2*x];
            sm%=mod;
            pre[x]++;
        }
        return sm;
    }
};