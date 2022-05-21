class Solution {
public:
    vector<int> coins;
    int inf = 0x3f3f3f3f;
    int memo[13][10001];
    int dp(int n, int amount){
        
        if(n==-1){
            if(amount==0)return 0;
            return inf;
        }
        
        // choose the n th //
        if(memo[n][amount]!=-1)return memo[n][amount];
        
        int ans = inf;
        if(amount>=coins[n])
        ans = min(ans, 1+dp(n, amount-coins[n]));
        
        ans=min(ans, dp(n-1, amount) );
        
        return memo[n][amount] = ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        Solution::coins=coins;
        
        memset(memo, -1, sizeof memo);
        int n=coins.size();
        int ans = dp(n-1, amount);
        
        if(ans<inf)return ans;
        else return -1;
    }
};