class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0, i = 0, ct = 0;
        while(i<nums.size()){
            if(nums[i]==0)ct = 0;
            else ct++;
            mx = max(mx, ct);
            i++;
        }
        return mx;
    }
};