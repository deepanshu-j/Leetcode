class Solution {
public:
    int n, inf;
    int memo[10005];
    int dp(int i, vector<int>& nums){
        
        if(i>=n-1)return 0;
        
        if(memo[i]!=-1)return memo[i];
        
        int res=inf;
        for(int j=1;j<=nums[i];++j){
            // j jumps from ith position 
            if(i+j>n)break;
            res=min(res, 1+dp(i+j, nums));
        }
        return memo[i]=res;
    }
    int jump(vector<int>& nums) {
        n=nums.size();
        inf=1e9+7;
        memset(memo, -1, sizeof memo);
        
        return dp(0, nums);
    }
};