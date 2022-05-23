class Solution {
public:
    int table[2][601];
    int inf = 0x3f3f3f3f;
    int memo[601][101][101];
    int dp(int i, int m, int n){
        
        if(i==-1){
            
            if(m>=0 and n>=0)return 0;
            else return -inf;
            
        }
        
        if(memo[i][m][n]!=-1)return memo[i][m][n];
        
        // take it  //
        int ans=0;
        if(table[0][i]<=m and table[1][i]<=n){
            ans=max(ans, 1+dp(i-1, m-table[0][i], n-table[1][i]));
        }
        
        // leave it  //
        
        ans = max(ans, dp(i-1, m, n));
        
        return memo[i][m][n] = ans;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        
        memset(memo, -1, sizeof memo);
        
        for(int i=0;i<sz;++i){
            
            string s=strs[i];
            
            int cnt_0=0, cnt_1=0;
            for(auto c: s)if(c=='1')++cnt_1;else ++cnt_0;
            
            table[0][i] = cnt_0;
            table[1][i] = cnt_1;
        }
        
        return dp(sz-1, m, n);
        
        
        return 0;
    }
};