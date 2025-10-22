#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class type1>
using ms= tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_multiset <ll> kek;
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        ms<long long> slid;
        for(int i=0;i<k;i++){
            slid.insert(nums[i]);
        }
        vector<double> ans;
        double val = *(slid.find_by_order(k/2));
        if(!(k&1)){
            val+=(*(slid.find_by_order(k/2-1)));
            val/=(2.0);
        }
        ans.push_back(val);
        for(int i=k;i<nums.size();i++){
            slid.insert(nums[i]);
            slid.erase(slid.find_by_order(slid.order_of_key(nums[i-k])));

            double val = *(slid.find_by_order(k/2));
            if(!(k&1)){
                val+=(*(slid.find_by_order(k/2-1)));
                // cout<<val<<endl;
                val/=(2.0);
            }
            ans.push_back(val);
        }
        return ans;
    }
};