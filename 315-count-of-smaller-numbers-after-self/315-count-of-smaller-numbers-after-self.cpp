
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
typedef tree<
    int,
    null_type,
    less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        ordered_set o_set;
        
        int n  = nums.size();
        
        vector<int> cnt(n, 0);
        for(int i=n-1; i>=0; --i){
            
            cnt[i] += o_set.order_of_key(nums[i]);
            
            o_set.insert(nums[i]);
        }
        
        return cnt;
    }
};