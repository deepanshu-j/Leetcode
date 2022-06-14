class Solution {
public:
    
    string word1, word2;
    int memo[501][501];
    int lcs(int i, int j){
        if(i>=word1.length() or j>=word2.length())return 0;
        
        if(memo[i][j]!=-1)return memo[i][j];
        
        if(word1[i]==word2[j])return memo[i][j] = 1+lcs(i+1, j+1);
        return memo[i][j] = max(lcs(i+1, j),lcs(i, j+1));
    }
    
    int minDistance(string word1, string word2) {
        Solution::word1 = word1;
        Solution::word2 = word2;
        
        memset(memo, -1, sizeof memo);
        
        int len = lcs(0, 0);
        
        int ans=word1.length() + word2.length() - (2*len);
        return ans;
    }
};