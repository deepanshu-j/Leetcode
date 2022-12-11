class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        
        int mx = nums[0];
        for(int i=1;i<n;++i){
            dp[i] = max(dp[i-1], 0) + nums[i];
            mx = max(dp[i], mx);
        }
        
        return mx;
    }
};