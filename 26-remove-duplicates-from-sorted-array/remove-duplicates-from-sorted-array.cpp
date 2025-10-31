class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        int it = 0;
        for(auto &x: st){
            nums[it]=x;
            it++;
        }
        return st.size();
    }
};