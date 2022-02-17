class Solution {
public:
    
    static const int bias=1001;

    int memo[21][3001];
    int dp(int n, int target, vector<int>& nums){
        if(n==-1) return target==0;
            
        
        if(memo[n][target+bias]!=-1)return memo[n][target+bias];
        
        int ans=0;
        // take it //
        if(nums[n]<=target)
            ans += dp(n-1, target-nums[n], nums);
        // leave it //
        ans += dp(n-1, target, nums);
        
        return memo[n][target+bias] = ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        memset(memo, -1, sizeof memo);
        
        int sum= accumulate(nums.begin(), nums.end(), 0);
        
        if((target+sum)&1)return 0;
        
        int new_target = (target+sum)/2;
        
        return dp(n-1, new_target, nums);
    }
};