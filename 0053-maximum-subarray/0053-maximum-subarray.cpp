class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        int cur_mx = nums[0];
        for(int i=1;i<n;++i){
            cur_mx = max({nums[i], cur_mx + nums[i]});
            mx = max(mx, cur_mx);
        }
        return mx;
    }
};