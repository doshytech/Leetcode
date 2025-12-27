class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto &x: nums)mp[x]++;
        set<pair<int,int>> st;
        for(auto &x: mp){
            st.insert({-x.second,x.first});
        }   
        vector<int> res;
        auto it = st.begin();
        int i = 0;
        while(it!=st.end()&&i<k){
            res.push_back((*it).second);
            it++, i++;
        }
        return res;
    }
};