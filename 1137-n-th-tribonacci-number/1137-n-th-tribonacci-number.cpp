class Solution {
public:
   
    int tribonacci(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);      
        int dp[n>2?n+1:3];
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;++i)
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        return dp[n];
    }
};