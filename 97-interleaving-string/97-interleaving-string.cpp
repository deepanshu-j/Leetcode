class Solution {
public:
    string s1, s2, s3;
    int n, m;
    int memo[201][201];
    bool dp(int i, int j){
        if(i==n and j==m)return true;
    
        if(memo[i][j]!=-1)return memo[i][j];
        
        bool ans = 0;
        
        if(s1[i]==s3[i+j])ans|=dp(i+1, j);
        if(s2[j]==s3[i+j])ans|=dp(i, j+1);
        
        return memo[i][j] = ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        Solution::s1 = s1;
        Solution::s2 = s2;
        Solution::s3 = s3;
        
        memset(memo, -1, sizeof memo);
        n = s1.length(), m = s2.length();
        if(n+m!=s3.length())return false;
        return dp(0, 0);
    }
};