using pii = pair<int,int>;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int lvl = 0;
        int m = grid.size(), n = grid[0].size(), good = 0;
        
        queue<pii> q;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(grid[i][j]==2)
                    q.push({i, j});
                else 
                if(grid[i][j]==1)
                    ++good;
        
        if(q.empty()){ // zero rotten //
            if(good>0)return -1;
            return 0;
        }
        
        auto check = [&](int x, int y)->bool{
            return (x>=0 and y>=0 and x<m and y<n);  
        };
        
        pii null_pair = {-1, -1};
        q.push(null_pair);
        
        int t = 0;
        
        while(!q.empty()){
            
            pii fr = q.front();
            q.pop();
            
            if(fr == null_pair){
                
                if(q.empty()){
                    break;
                }
                ++t;
                q.push(null_pair);
                
            }
            
            int x = fr.first, y = fr.second;
            if(check(x-1, y) and grid[x-1][y]==1) grid[x-1][y] = 2, q.push({x-1, y});
            if(check(x, y-1) and grid[x][y-1]==1) grid[x][y-1] = 2, q.push({x, y-1});
            if(check(x+1, y) and grid[x+1][y]==1) grid[x+1][y] = 2, q.push({x+1, y});
            if(check(x, y+1) and grid[x][y+1]==1) grid[x][y+1] = 2, q.push({x, y+1});
            
        }
        bool got_one = 0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(grid[i][j]==1)
                    got_one = 1;
        
        if(got_one)return -1;
        return t;
    }
};