class Solution {
public:
    int n, m;
    string s1, s2, s3;
    int memo[101][101];
    bool dp(int i, int j){
        if(i==n and j==m)return 1;
        
        
        if(i<n and j<m and memo[i][j]!=-1)return memo[i][j];
        
        int ans=0;
        if(i<n and s1[i]==s3[i+j]){
            ans |= dp(i+1, j);
        }
        if(j<m and s2[j]==s3[i+j]){
            ans |= dp(i, j+1);
        }
        
        return memo[i][j]=ans;
    }
    
    bool isInterleave(string s11, string s22, string s33) {
        
        s1=s11;
        s2=s22;
        s3=s33;
        
        memset(memo, -1, sizeof memo);
        
        n=s1.length(), m=s2.length();
        if(n+m!=s3.length())return 0;
        
        return dp(0,0);
    }
};