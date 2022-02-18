class Solution {
public:
    int n, m;
    string word1, word2;
//     int memo[1001][1001];
//     int dp(int i, int j){
        
//         // i<n and j>=0
//         if(i==n-1 and j==0){
//             if(word1[i]==word2[j])
//                 return 2;
//             else
//                 return 1;
//         }
        
//         if(i==n or j==-1){ // one of them is still remaining 
//             // move on the other string //
            
            
            
//         }
        
//         if(memo[i][j]!=-1)return memo[i][j];
        
//         int ans=0;
//         if(word1[i]==word2[j]){
//             ans = max(ans, 2 + dp(i+1, j-1));
//         }
//         ans = max({ ans, dp(i+1, j), dp(i, j-1) });
//         return memo[i][j]=ans;
//     }
    
    string s;
    
    int memo[2001][2001][2];
    int dp(int i, int j, bool must_take){
        
        if(i>j)return 0;
        
        if(must_take and (i>n-1 or j<=n-1 ))return 0; // you haven't taken anything from either Ist str or IInd str
        
        if( memo[i][j][must_take]!=-1)return memo[i][j][must_take];
        
        int ans=0;
        if(s[i]==s[j]){
            if(i==j){
                ans=max(ans, 1+dp(i+1, j-1, must_take)); // this will the odd center palindrome //
            }else{
                ans=max(ans, 2+dp(i+1, j-1, 0));
            }
        }
        else{
            ans=max(ans, dp(i+1, j, must_take));
            ans=max(ans, dp(i, j-1, must_take));
        }
        return memo[i][j][must_take]=ans;
    }
    
    int longestPalindromeSubseq(string s_local_copy) {
        memset(memo, -1, sizeof memo);
        s=s_local_copy;
        int n=s.length();
        return dp(0, n-1, 1);
    }
    
    int longestPalindrome(string word11, string word22) {
        word1=word11;
        word2=word22;
        n=word1.length();
        m=word2.length();
        
//         memset(memo, -1, sizeof memo);
        
        int res = longestPalindromeSubseq(word11+word22);
        // int res=dp(0, m-1);
        
        if(res==1){
            res=0;
        }
    
        return res;
    }
};