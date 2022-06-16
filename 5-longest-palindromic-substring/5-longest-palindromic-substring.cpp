class Solution {
public:
    string s;
    int memo[1001][1001];
    
    int dp(int i, int j){
        if(i>j)return false;
        if(i==j)return true;
        if(i+1==j) return (s[i]==s[j]);
        
        if(memo[i][j]!=-1)return memo[i][j];
        
        if(s[i]==s[j])return memo[i][j] = dp(i+1, j-1);
        
        return memo[i][j] = false;
    }
    
    string longestPalindrome(string s) {
        Solution::s = s;
        int n=s.size();

        memset(memo, -1, sizeof memo);
        
        int mx=1, x=0, y=0;
        for(int i=0;i<n;++i){
            for(int j=0; j<n; ++j){
                if(dp(i, j)){
                    if(j-i+1>mx){
                        mx = j-i+1;
                        x=i;
                        y=j;
                    }
                }
            }
        }
        
        string ans="";
        for(int i=x;i<=y;++i)ans += s[i];
        return ans;
    }
};