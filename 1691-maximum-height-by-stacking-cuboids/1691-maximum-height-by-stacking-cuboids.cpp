#define all(x) x.begin(), x.end()
class Solution {
public:
    
    int memo[101][101];
    vector<vector<int>> cuboids;
    // dp[i][j] can we place the ith cuboid considering that jth cuboid was the last placed so ith must adhere to consith with j else we cant place this 
    int dp(int i, int j){
        
        // base case //
        if(i==-1 or j==0)return 0;
        
        if(j!=-1 && memo[i][j]!=-1)return memo[i][j];
        
        int ans=0;
        if(j==-1){ // can place anyone //
            ans =max(ans, dp(i-1, i) + cuboids[i][2]); // i will be the last placed //
        }
        
        // some one is already placed , check j with i
        bool ok=1;
        for(int k=0;k<3;++k)
        ok &= (j!=-1 && cuboids[i][k] <= cuboids[j][k] );
        
        if(ok){
            ans = max(ans, dp(i-1, i) + cuboids[i][2] );
        }
        
        // donot place this cuboid //
        ans = max(ans, dp(i-1, j));
        if(j!=-1)
        return memo[i][j] = ans;
        else
            return ans;
    }
    
    int maxHeight(vector<vector<int>>& cuboids_local_copy) {
        
        cuboids=cuboids_local_copy;
        
        for(auto &x: cuboids)
            sort(all(x));
        
        sort(all(cuboids));
        
        memset(memo, -1, sizeof memo);
        
        int n=cuboids.size();
        
        return dp(n-1, -1);
    }
};