class Solution {
public:
    
    static const int bias=1001;
    // int memo[21][bias+2005];
    int dp(int n, int target, vector<int>& nums){
        
        if(n==-1)return target==0;
        
        int ans=0;
        
        // if(memo[n][bias+target]!=-1)return memo[n][bias+target];
        
        // If we take nth index as +ve // 
        ans += dp(n-1, target-nums[n], nums);
        // Take nth index as -ve //
        ans += dp(n-1, target+nums[n], nums);
        
        // return memo[n][bias+target]=ans;
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        // memset(memo, -1, sizeof memo);
        
        return dp(n-1, target, nums);
    }
};