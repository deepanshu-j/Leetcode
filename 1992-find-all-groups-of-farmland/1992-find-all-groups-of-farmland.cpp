class Solution {
public:
    using pii = pair<int,int>;
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        
        auto in = [&](int x, int y)->bool{
          return (x>=0 and y>=0 and x<m and y<n);  
        };
        
        int end_x, end_y;
        function<void(int,int)> dfs = [&](int x, int y)->void{
            if(!in(x,y)) return;
            if(land[x][y] == 0) return;
            land[x][y] = 0;
            if(end_x < x or end_y < y)
                end_x = x, end_y = y;
            
            dfs(x, y+1);
            dfs(x+1, y);
        };
        
        vector<vector<int>> ans;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(land[i][j] == 0) continue;
                end_x = i, end_y = j;
                dfs(i, j);
                ans.push_back({i, j, end_x, end_y});
            }
        }
        
        return ans;
    }
};