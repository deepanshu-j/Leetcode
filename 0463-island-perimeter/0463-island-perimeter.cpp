class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans =0;
        
        auto isInside = [&](int i, int j)->bool{
            return (i>=0 and j>=0 and i<m and j<n);
        };
        
        auto isAdj = [&](int i, int j)->bool{
            if(!isInside(i, j)) return 1;
            return (isInside(i, j) && grid[i][j] == 0);
        };
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j] == 0) continue;
                ans += isAdj(i+1, j);
                ans += isAdj(i-1, j);                       
                ans += isAdj(i, j+1);
                ans += isAdj(i, j-1);
            }
        }
        
        return ans;
    }
};