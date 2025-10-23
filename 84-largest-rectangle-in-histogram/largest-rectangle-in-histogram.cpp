class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int,int>> stk;
        int ans = 0;
        for(int i=0;i<n;i++){
            int st = i;
            while(stk.size()&&stk.top().first>heights[i]){
                int h = stk.top().first, j = stk.top().second;
                stk.pop();
                int w = i-j;
                ans = max(w*h, ans);
                st = j;
            }
            stk.push({heights[i],st});
        }
        while(stk.size()){
            int h = stk.top().first, j = stk.top().second;
            stk.pop();
            int w = n-j;
            ans = max(h*w, ans);
        }
        return ans;
    }
};