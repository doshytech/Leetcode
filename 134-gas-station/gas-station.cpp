class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // if(n==1&&)return 0;
        vector<int> gas1=gas, cost1=cost;
        for(int i=0;i<n;i++){
            gas1.push_back(gas[i]);
            cost1.push_back(cost[i]);
        }
        for(int i=0;i<n;i++){
            if(gas1[i]>=cost1[i]){
                int sm = 0;
                bool tk = true;
                for(int j=i;j<i+n;j++){
                    sm+=gas1[j]-cost1[j];
                    if(sm<0){
                        i = j;
                        tk = false;
                        break;
                    }
                }
                if(tk)return i;
            }
        }
        return -1;
    }
};