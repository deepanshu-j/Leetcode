class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        const int inf = 1e9;
        int dp[n+1][k+3]; // from ith node in atmost k nodes how much distance // 
        for(int i=0;i<=n;++i) for(int j=0;j<=k+2;++j) dp[i][j] = inf;
        for(int i=0;i<=k+2;++i) dp[src][i] = 0; 
        
        for(int i=1;i<k+2;++i){
            for(auto f : flights){
                int u = f[0], v = f[1], d = f[2];
                dp[v][i] = min(dp[v][i], d + dp[u][i-1]);
            }
        }
        
        if(dp[dst][k+1] >= inf) return -1;
        return dp[dst][k+1];
    }
};