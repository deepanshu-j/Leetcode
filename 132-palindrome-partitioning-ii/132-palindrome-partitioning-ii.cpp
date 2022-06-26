class Solution {
public:
    int ispalin[2001][2001];
    int n;
    void pre(string &s){
        
        n = s.size();
        
        // odd center //
        for(int i=0;i<n;++i){    
            ispalin[i][i] = 1;
            
            int len = 1;
            while(i-len>=0 and i+len<n and s[i-len]==s[i+len]){
                ispalin[i-len][i+len]=1;
                ++len;
            }
        }
        
        // even center //
        for(int i=0;i<n-1;++i){
            int len = 0;
            while(i-len>=0 and i+1+len<n and s[i-len]==s[i+1+len]){
                ispalin[i-len][i+1+len]=1;
                ++len;
            }
        }
        
    }
    
    int memo[2001];
    int dp(int i){
        
        if(ispalin[i][n-1])return 0;
        
        if(memo[i]!=-1)return memo[i];
        
        int ans = n-i;
        for(int j=i;j<n-1;++j){
            if(ispalin[i][j]){
                ans = min(ans, 1+dp(j+1));
            }
        }
        
        return memo[i] = ans;
    }
    
    int minCut(string s){
        memset(ispalin, 0, sizeof ispalin);
        memset(memo, -1, sizeof memo);
        pre(s);
        
        return dp(0);
    }
};