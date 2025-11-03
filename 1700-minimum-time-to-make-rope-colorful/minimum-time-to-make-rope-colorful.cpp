class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // set<int> st;
        int ans = 0,i = 0, n = colors.size();
        while(i<n){
            int j = i;
            multiset<int> st;
            while(j<n&&colors[j]==colors[i]){
                st.insert(neededTime[j]);
                j++;
            }
            st.erase(--st.end());
            if(st.size()){
                for(auto &x: st)ans+=x;
            }
            i = j;
        }
        return ans;
    }
};