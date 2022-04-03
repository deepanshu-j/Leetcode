class Solution {
public:
    
    int memo[1001][2001];
    int dp(int n, int k, vector<vector<int>>& piles){
        // choose as many you can from nth pile //
        if(n==-1 or k==0)return 0;
        
        if(memo[n][k]!=-1)return memo[n][k];
        
        int res=dp(n-1, k, piles);
        int sum=0;
        int lim=min(k, (int)piles[n].size());
        for(int i=0;i<lim;++i){
            sum += piles[n][i];
            res= max(res, sum + dp(n-1, k-(i+1), piles));
        }
        return memo[n][k]=res;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        memset(memo, -1, sizeof memo);
        return dp(piles.size()-1, k, piles);    
    }
};