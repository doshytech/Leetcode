class Solution {
public:
    bool check(vector<int>& nums) {
        for(int i=0;i<1000;i++){
            if(sorted(nums))return true;
            rotate(nums);
        }
        return false;
    }
    bool sorted(vector<int> &nums){
        vector<int> dum = nums;
        sort(dum.begin(),dum.end());
        for(int i=0;i<dum.size();i++){
            if(nums[i]!=dum[i])return false;
        }
        return true;
    }
    void rotate(vector<int> &nums){
        vector<int> dum;
        for(int i=1;i<nums.size();i++){
            dum.push_back(nums[i]);
        }
        dum.push_back(nums[0]);
        nums = dum;
    }
};