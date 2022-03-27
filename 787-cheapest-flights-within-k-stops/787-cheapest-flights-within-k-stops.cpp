class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        const int inf=1e9;
        int dp[k+2][n];
        
        for(int i=0;i<k+2;++i)
            for(int v=0;v<n;++v)
                dp[i][v]=inf;
        for(int i=0;i<k+2;++i) dp[i][src]=0;
        
        for(int i=1;i<k+2;++i){
            for(auto &edge: flights){
                int u=edge[0],v=edge[1],w=edge[2];
                
                dp[i][v]=min({dp[i][v], dp[i-1][u]+w});
            }
        }
        
        return ((dp[k+1][dst]==inf)?-1:dp[k+1][dst]);
    }
};