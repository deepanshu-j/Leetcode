class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        
        int ans = -1e5;
        dp[0] = nums[0]; 
        for(int i=0;i<n;++i){
            int prev = -1e5; 
            if(i>0) prev = dp[i-1]+nums[i];
            dp[i] = max(prev, nums[i]);
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};