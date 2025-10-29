vector<int> ans;
class Solution {
public:
    int nextBeautifulNumber(int n) {
        if(ans.size()){
            return *(upper_bound(ans.begin(),ans.end(),n));
        }
        else{
            for(int i=1;i<1500000;i++){
                unordered_map<int,int> ct;
                int j = i;
                while(j){
                    ct[j%10]++;
                    j/=10;
                }
                bool val = true;
                for(auto &x: ct){
                    if(x.first!=x.second){
                        val = false;
                        break;
                    }
                }
                if(val)ans.push_back(i);
            }
            return nextBeautifulNumber(n);
        }
    }
};