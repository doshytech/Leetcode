class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.length();
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<int> dp(n+1, false);
        dp[n] = true;

        for(int start = n; start >= 0; start--) {
            string temp;
            for(int i=start; i<n; i++) {
                temp.push_back(s[i]);
                if(words.count(temp) && dp[i + 1]) {
                    dp[start] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};