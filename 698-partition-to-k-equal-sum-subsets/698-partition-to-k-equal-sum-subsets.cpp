class Solution {
public:
    
    int n;
    vector<int> nums;
    int targetSum;
    int memo[16][1<<16+1];
    // kth bucket you're on and current state of taken elements
    bool dp(int k, int mask, int sum){
        
        if(k==0)return ( mask == (1<<n)-1 );
        
        if(memo[k][mask]!=-1)return memo[k][mask];
        
        bool ans = 0;
        for(int i=0;i<n;++i){
            if((mask&(1<<i)) == 0){
                
                // take it // 
                sum -= nums[i];
                
                if(sum == 0){
                    ans |= dp(k-1, mask | (1<<i), targetSum );
                }else
                if(sum > 0)
                    ans |= dp(k,  mask | (1<<i), sum );
                
                sum += nums[i];
            }
        }
        
        return memo[k][mask] = ans;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        this->nums = nums;
        this->n = nums.size();
        
        this->targetSum = accumulate(nums.begin(), nums.end(), 0);
        if(targetSum%k != 0)return false;
        targetSum /= k;  
        
        memset(memo, -1, sizeof memo);
        
        return dp(k, 0, targetSum );
        
    }
};