class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mn = complexity[0];
        int n = complexity.size();
        int mod = 1e9+7;
        vector<int> fact(n+1);
        fact[0]=1;
        for(int i=1;i<complexity.size();i++){
            if(complexity[i]<=mn)return 0;
        }
        for(int i=0;i<complexity.size();i++){
            fact[i+1]=((i+1)*1LL*fact[i])%mod;
        }
        return fact[n-1];
    }
};