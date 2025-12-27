class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sm = 0, o = 0, e = 0, m = 1e9+7;
        long long res = 0;
        for(auto &x: arr){
            sm+=x;
            if(sm&1){
                res+=e;
                res++;
                o++;
            }
            else{
                res+=o;
                e++;
            }
        }
        return res%m;
    }
};