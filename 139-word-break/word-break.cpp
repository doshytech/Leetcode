class Solution {
public:
    set<string> st;
    map<string,int> dp[301];
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto &x: wordDict)st.insert(x);
        return f(0,s,"");
    }
    int f(int i,string &s, string curr){
        if(i==s.size())return !curr.size();
        if(dp[i].find(curr)!=dp[i].end())return dp[i][curr];
        curr.push_back(s[i]);
        bool ans = f(i+1,s,curr);
        if(st.find(curr)!=st.end()){
            ans|=f(i+1,s,"");
        }
        return dp[i][curr]=ans;
    }
};