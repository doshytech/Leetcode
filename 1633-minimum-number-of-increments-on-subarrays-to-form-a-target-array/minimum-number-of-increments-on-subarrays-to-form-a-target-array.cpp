class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        int c = target[0];
        for(auto &x: target){
            if(x>=c)ans+=x-c;
            c = x;
        }
        return ans;
    }
};