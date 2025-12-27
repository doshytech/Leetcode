class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i&&nums[i]==nums[i-1]){
                continue;
            }
            int j = i +1;
            int k = nums.size()-1;
            while(j<k){
                int sm = nums[j]+nums[i]+nums[k];
                if(sm>0)k--;
                else if(sm<0)j++;
                else{
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while(j<k&&nums[j]==nums[j-1])j++;
                }
            }
        }
        return res;     
    }
};