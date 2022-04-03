class Solution:
    
    piles=[] 
    
    @cache
    def dp(self, n, k):
        if n==-1 or k==0: return 0
        
        res = self.dp(n-1, k)
        lim = min(k, len(self.piles[n]))
        s=0
        for i in range(lim):
            s += self.piles[n][i]
            res = max(res, s+self.dp(n-1, k-i-1))
        return res
        
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        Solution.piles=piles
        n=len(piles)-1
        return self.dp(n,k)
        