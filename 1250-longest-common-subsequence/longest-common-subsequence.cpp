class Solution {
public:
    int n, m;
    // vector<vector<int>> dp;
    int longestCommonSubsequence(string a, string b) {
        n = a.size(), m = b.size();
        int dp[1001][1001];
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
        // memset(dp,0,sizeof(dp));
        // dp.resize(n+1, vector<int> (m+1,0));
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
        // for(auto &x: p)cout<<x<<" ";
        // cout<<endl;
        // for(auto &x: c)cout<<x<<" ";
        return p[0];
    }
    // int f(int i, int j, string &a, string &b){
    //     if(i==n||j==m)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(a[i]==b[j])return dp[i][j]=1+f(i+1,j+1,a,b);
    //     else return dp[i][j]=max(f(i+1,j,a,b),f(i,j+1,a,b));
    // }
};