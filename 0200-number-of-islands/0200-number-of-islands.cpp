class Solution {
public:
    vector<vector<char>> grid_g;
    vector<vector<bool>> done; 
    void dfs(int i, int j){
        //handeling bad cases//
        if( i<0 || j<0 || i>=grid_g.size() || j>=grid_g[0].size() || grid_g[i][j]=='0' ){
            return;
        }
        
        if(done[i][j]){
            return;
        }
        
        done[i][j]=true;
        
        dfs(i+1,j);
        dfs(i,j+1);
        dfs(i-1,j);
        dfs(i,j-1);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        grid_g=grid;
        
        done.resize(grid.size(), vector<bool>(grid[0].size(),false));// POE accessing the 1st el//
        
        int cnt=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(!done[i][j] && grid[i][j]=='1'){
                    ++cnt;
                    dfs(i,j);
                }
            }
        }
        return cnt;
    }
};