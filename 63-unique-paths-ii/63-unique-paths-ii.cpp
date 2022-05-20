class Solution {
public:
    long long dp[101][101]{0};
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        
        if(!obstacleGrid[m-1][n-1])dp[m-1][n-1]=1;
        
        auto inside = [&](int x, int y)->bool{
            return  (x>=0 and y>=0 and x<m and y<n);
        };
        
        for(int i=m-1;i>=0;--i){
            for(int j=n-1;j>=0;--j){
                if(inside(i+1, j) and !obstacleGrid[i+1][j]){
                    dp[i][j] += dp[i+1][j]; 
                }
                if(inside(i, j+1) and !obstacleGrid[i][j+1]){
                    dp[i][j] += dp[i][j+1];
                }
            }
        }
        
        if(obstacleGrid[0][0])return 0;
        
        return dp[0][0];
    }
};