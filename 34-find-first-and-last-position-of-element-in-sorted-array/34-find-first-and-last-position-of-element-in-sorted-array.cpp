class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        auto st = lower_bound(nums.begin(), nums.end(), target);
        int st_idx = st - nums.begin();
        
        
        auto end = upper_bound(nums.begin(), nums.end(), target);
        int end_idx = end - nums.begin();
        
        if(end_idx - st_idx == 0 ){
            vector<int> ans{-1, -1};
            return ans;
        }
        
        vector<int> ans{st_idx, end_idx - 1};
        
        return ans;
        
    }
};