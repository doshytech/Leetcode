class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int longestCommonSubsequence(string a, string b) {
        n = a.size(), m = b.size();
        // vector<int> p(m+1,0), c(m+1,0);
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(a[i-1]==b[j-1]){
        //             c[j]=1+p[j-1];
        //         }
        //         else{
        //             c[j]=max(p[j], c[j-1]);
        //         }
        //     }
        //     p = c;
        // }
        // return p[m];
        // memset(dp,-1,sizeof(dp));
        dp.resize(n, vector<int> (m,-1));
        return f(0,0,a,b);
    }
    int f(int i, int j, string &a, string &b){
        if(i==n||j==m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j])return dp[i][j]=1+f(i+1,j+1,a,b);
        else return dp[i][j]=max(f(i+1,j,a,b),f(i,j+1,a,b));
    }
};