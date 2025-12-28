class Solution {
public:
    int n, m;
    int longestCommonSubsequence(string a, string b) {
        n = a.size(), m = b.size();
        vector<int> p(m+1,0), c(m+1,0);
        for(int i=n-1;i>-1;i--){
            for(int j=m-1;j>-1;j--){
                int not_take = max(p[j],c[j+1]);
                int take = 0;
                if(a[i]==b[j])take = 1+p[j+1];
                c[j]=max(take, not_take);
            }
            p = c;
        }
        return p[0];
    }
};