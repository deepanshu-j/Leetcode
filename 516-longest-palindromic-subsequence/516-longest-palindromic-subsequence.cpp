class Solution {
public:
     
    string s;
    
    int memo[1001][1001];
    int dp(int i, int j){
        
        if(i>j)return 0;
        
        if(memo[i][j]!=-1)return memo[i][j];
        
        int ans=0;
        if(s[i]==s[j]){
            if(i==j){
                ans=max(ans, 1+dp(i+1, j-1));
            }else{
                ans=max(ans, 2+dp(i+1, j-1));
            }
        }
        else{
            ans=max(ans, dp(i+1, j));
            ans=max(ans, dp(i, j-1));
        }
        return memo[i][j]=ans;
    }
    
    int longestPalindromeSubseq(string s_local_copy) {
        memset(memo, -1, sizeof memo);
        s=s_local_copy;
        int n=s.length();
        return dp(0, n-1);
    }
};