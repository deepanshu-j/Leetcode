class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // idea is to maintain a ds which holds min of whole row but without that index
        
        // basically dp[i][j] = min(row[i]) not including jth element
        // this can be done easilty via pre suf min of dp for every row //
        
        int n = grid.size();
        
        vector<vector<int>> dp(n, vector<int>(n,0));
        
        for(int j=0;j<n;++j) dp[n-1][j] = grid[n-1][j];
        vector<int> pre_dp(n), suf_dp(n);
        
        // compiute pre_dp and suf_dp //
        pre_dp[0] = dp[n-1][0];
        for(int j=1;j<n;++j) pre_dp[j] = min(dp[n-1][j], pre_dp[j-1]); 
        
        suf_dp[n-1] = dp[n-1][n-1];
        for(int j=n-2;j>=0;--j) suf_dp[j] = min(dp[n-1][j], suf_dp[j+1]);
        
        for(int r = n-2;r>=0; --r){
            for(int c = 0; c<n; ++c){
                int best = INT_MAX;
                if(c-1>=0) best = min(best, pre_dp[c-1]);
                if(c+1<n) best = min(best, suf_dp[c+1]);
                dp[r][c] = grid[r][c] + best;
            }
            // now update the pre_dp and suf_dp //
            pre_dp[0] = dp[r][0];
            for(int j=1;j<n;++j) pre_dp[j] = min(dp[r][j], pre_dp[j-1]); 

            suf_dp[n-1] = dp[r][n-1];
            for(int j=n-2;j>=0;--j) suf_dp[j] = min(dp[r][j], suf_dp[j+1]);
        }
        
        int ans = dp[0][0];
        for(int i=0;i<n;++i) ans = min(ans, dp[0][i]);
        return ans;
    }
};