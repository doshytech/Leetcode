class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int s = 0, t = 0;
        for(auto &x: nums){
           s = (s^x)&(~t);
           t = (t^x)&(~s);
        }
        return s;
    }
};