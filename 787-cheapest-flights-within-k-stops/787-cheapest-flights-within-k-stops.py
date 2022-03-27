class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        
        # Bellman-Ford #
        
        inf = (int)(1e9+7)
        dp = [ [inf for _ in range(n)] for __ in range(k+2)]
        
        for i in range(0,k+2):
            dp[i][src]=0
        
        for i in range(1,k+2):
            for [u, v, w] in flights:
                dp[i][v]=min(dp[i][v], dp[i-1][u] + w)
        
        # return dp
        return (-1 if dp[k+1][dst]==inf else dp[k+1][dst]) 
    