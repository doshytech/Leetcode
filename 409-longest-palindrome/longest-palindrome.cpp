class Solution {
public:
    int longestPalindrome(string s) {
        int ct = 0;
        map<char,int> v;
        for(auto &x: s)v[x]++;
        int sm = 0;
        for(auto &x: v){
            sm+=x.second-(x.second&1);
            ct|=(x.second&1);
        }
        return sm+ct;
    }
};