class Solution {
public:
    
    int memo[51][51][51];
    int m, n;
    const int MOD = 1e9 + 7;
    bool is_inside(int i, int j){
        return (i>=0 and j>=0 and i<m and j<n);
    }
    
    int dp(int i, int j, int hops){
        if(hops==0){
            return !is_inside(i, j);
        }
        
        if(!is_inside(i, j))return 1;
        
        if(memo[i][j][hops]!=-1)return memo[i][j][hops];
        
        int ans = 0;
        ans = (ans%MOD + dp(i-1, j, hops-1)%MOD )%MOD;
        ans = (ans%MOD + dp(i+1, j, hops-1)%MOD )%MOD;
        ans = (ans%MOD + dp(i, j-1, hops-1)%MOD )%MOD;
        ans = (ans%MOD + dp(i, j+1, hops-1)%MOD )%MOD;

        return  memo[i][j][hops] = ans%MOD;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m  = m, this->n = n;
        
        memset(memo, -1, sizeof memo);
        
        int res =  dp(startRow, startColumn, maxMove);
       
        return res;
    }
};