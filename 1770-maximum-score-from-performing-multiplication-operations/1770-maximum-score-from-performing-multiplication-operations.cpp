class Solution {
public:
    
    vector<int> nums, multipliers;
    
    int n, m;
    int memo[1001][1001];
    
    int dp(int i, int k){
        
        // cout<<"i:"<<i<<" ,k:"<<k<<"\n";
        if(k == m)return 0;
        
        if(memo[i][k] != -1e9) return memo[i][k];
        
        // k elements are taken //
        // 0..n-1
        
        int left = i;
        // tot taken elements = k
        int j = n-1-(k-i); 
        
        int ans = max(
            nums[i]*multipliers[k] + dp(i+1, k+1),
            nums[j]*multipliers[k] + dp(i, k+1)
        );
        
        return memo[i][k] = ans;
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        
        this->nums = nums;
        this->multipliers = multipliers;
        
        this->n = nums.size();
        this->m = multipliers.size();
        
        
        for(int i=0;i<1001;++i)
            for(int j=0;j<1001;++j)
                memo[i][j] = -1e9;
        
        return dp(0, 0);
    }
};