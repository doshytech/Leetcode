class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int b = INT_MAX,a=INT_MAX;
        int ct1=0,ct2=0;
        for(auto &x: nums){
            if(x==a)ct1++;
            else if(x==b)ct2++;
            else if(ct1==0)a=x,ct1=1;
            else if(ct2==0)b=x,ct2=1;
            else ct1--,ct2--;
        }
        vector<int> v;
        if(count(nums.begin(),nums.end(),a)>n/3)v.push_back(a);
        if(count(nums.begin(),nums.end(),b)>n/3)v.push_back(b);
        // int n = nums.size(), a = -1, b = -1;
        // int ct = 0, ctt = 0;
        // for(auto &x: nums){
        //     if(x==a)ct++;
        //     else if(x==b)ctt++;
        //     else if(ct==0)a=x,ct=1;
        //     else if(ctt==0)b=x, ctt=1;
        //     else ct--, ctt--;
        // }
        // vector<int> v;
        // if(count(v.begin(),v.end(),a)>n/3)v.push_back(a);
        // if(count(v.begin(),v.end(),b)>n/3)v.push_back(b);
        return v;
    }
};