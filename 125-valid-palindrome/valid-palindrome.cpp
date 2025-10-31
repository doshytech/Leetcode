class Solution {
public:
    bool isPalindrome(string s) {
        string p, q;
        for(auto &x: s){
            int cp = tolower(x);
            if((cp>='a'&&cp<='z')||(cp>='0'&&cp<='9'))p.push_back(cp);
        }
        q = p;
        reverse(p.begin(),p.end());
        return p==q;
    }
};