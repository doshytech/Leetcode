class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int sm = 0;
        int cr = 0, pr = 0;
        vector<int> v;
        for(auto &x: bank){
            int ct = count(x.begin(),x.end(),'1');
            if(ct){
                v.push_back(ct);
            }
        } 
        stack<int> stk;
        for(auto &x: v){
            // while(stk.size()&&stk.top()<x){
            //     sm+=(x*stk.top());
            //     stk.pop();
            // }
            stk.push(x);
        }
        int p = 0;
        while(stk.size()){
            sm+=(p*stk.top());
            p = stk.top();
            stk.pop();
        }
        return sm;
    }
};