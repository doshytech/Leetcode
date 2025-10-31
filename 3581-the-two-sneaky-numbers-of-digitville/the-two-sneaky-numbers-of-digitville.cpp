class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> v;
        unordered_set<int> st;
        for(auto &x: nums){
            if(st.find(x)!=st.end())v.push_back(x);
            st.insert(x);
        }
        return v;
    }
};