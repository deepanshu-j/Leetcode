class Solution {
public:
    int m, n;
    void dfs(int i, int j, int &cnt, vector<vector<int>> &grid){
        
        grid[i][j]=0;
        ++cnt;
        
        if(i-1>=0 and grid[i-1][j]==1)dfs(i-1, j, cnt, grid);
        if(i+1<m and grid[i+1][j]==1)dfs(i+1, j, cnt, grid);
        if(j-1>=0 and grid[i][j-1]==1)dfs(i, j-1, cnt, grid);
        if(j+1<n and grid[i][j+1]==1)dfs(i, j+1, cnt, grid);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        this->m = grid.size(), this->n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){
                    int cnt = 0;
                    dfs(i, j, cnt, grid);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};