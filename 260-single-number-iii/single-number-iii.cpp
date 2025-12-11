class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xr = 0;
        for(auto &x: nums)xr^=x;
        long long val = (xr&(xr-1))^xr;
        int a = 0, b = 0;
        for(auto &x: nums){
            if(x&val)a^=x;
            else b^=x;
        }
        return {a,b};
    }
};