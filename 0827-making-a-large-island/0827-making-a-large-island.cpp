
using pii = pair<int,int> ;
class Solution {
public:
    
    
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        set<pii> vis;
        stack<pii> currentPath;
        
        auto isInside = [&](pii p)->bool{
            return (p.first >=0 and p.second>=0 and 
                p.first<n and p.second < n);
        };
        
        function<void(pii)> dfs;
        dfs = [&](pii p){
            if(not isInside(p)) return;
            if(grid[p.first][p.second] == 0) return;
            if(vis.find(p) != vis.end()) return;
            
            currentPath.push(p);
            vis.insert(p);
            
            dfs({p.first+1, p.second});
            dfs({p.first, p.second+1});
            dfs({p.first-1, p.second});
            dfs({p.first, p.second-1});
        };
        
        int color = 2;
        map<pii, int> mp;
        int mx = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]!= 1) continue;
                
                dfs({i, j});
                ++color;
                int stackSize = currentPath.size();
                while(!currentPath.empty()){
                    pii top = currentPath.top();
                    currentPath.pop();
                    grid[top.first][top.second] = color; 
                    mp[top] = stackSize;
                }
                
                mx = max(mx, stackSize);
                
                vis.clear();
            }
        }
        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j] == 0){
                    
                    set<pii> s; // {color, size} //
                    if(isInside({i+1, j}))
                        s.insert({grid[i+1][j], mp[make_pair(i+1, j)]});
                    
                    if(isInside({i, j+1}))
                        s.insert({grid[i][j+1], mp[make_pair(i, j+1)]});
                    
                    if(isInside({i-1, j}))
                        s.insert({grid[i-1][j], mp[make_pair(i-1, j)]});
                    
                    if(isInside({i, j-1}))
                        s.insert({grid[i][j-1], mp[make_pair(i, j-1)]});
                    
                    int sum = 1;
                    for(pii el: s) sum += el.second;
                    mx = max(mx, sum);
                }
            }
        }
        
        return mx; 
    }
    
    
};