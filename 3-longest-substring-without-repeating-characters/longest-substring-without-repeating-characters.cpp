class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> cr;
        int i = 0, j = 0, n = s.size();
        int mx = 0;
        while(i<n){
            while(cr[s[i]]){
                cr[s[j]]--;
                j++;
            }
            cr[s[i]]++;
            mx = max(mx, i-j+1);
            i++;
        }
        return mx;
    }
};