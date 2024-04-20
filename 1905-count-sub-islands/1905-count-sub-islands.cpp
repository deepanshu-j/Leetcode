class Solution {
public:
    using pii = pair<int,int>;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        auto in = [&](int x, int y){
            return (x>=0 and y>=0 and x<m and y<n);
        };
        
        vector<pii> tour;
        function<void(int, int)> dfs = [&](int x, int y)->void{
            if(!in(x, y)) return;
            if(grid2[x][y] == 0) return;
            grid2[x][y] = 0;
            tour.push_back({x, y});
            dfs(x+1, y);
            dfs(x, y+1);
            dfs(x-1, y);
            dfs(x, y-1);
        };
        
        int ans = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid2[i][j] == 0) continue;
                tour = {};
                dfs(i, j);
                bool f = 1;
                for(auto [x,y]: tour){
                    if(grid1[x][y] == 0) f = 0;
                }
                ans += f;
            }    
        }
        return ans;
    }
};