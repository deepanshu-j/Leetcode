#define pii pair<int,int> 
#define inf 0x3f3f3f3f
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        // bfs for shortest path because edge weight = 1 // 
        
        int n=grid.size();
        int dist[n+1][n+1];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                dist[i][j]=inf;
            }
        }
        
        pii nullpair={-1, -1};
        
        auto is_valid=[&n, &grid](int x, int y)->bool{
            return (x>=0 and y>=0 and x<n and y<n and grid[x][y]==0);
        };
        
        queue<pii> q;
        q.push(nullpair);
        if(grid[0][0]==0)
        q.push({0, 0});
        
        int level=0;
        while(1){
            
            auto fr = q.front();
            q.pop();
            
            if(q.empty())break;
            
            q.push(nullpair);
            level++; 
            dist[0][0]=1;
            
            while(q.front()!=nullpair){
                fr = q.front();
                q.pop();
                int x=fr.first, y=fr.second;
                // process this //
                for(int i=-1;i<=1;++i){
                    for(int j=-1;j<=1;++j){
                        if(not (i==0 and j==0)){
                            if(is_valid(x-i, y-j) and (dist[x-i][y-j]>1+level) ){
                                dist[x-i][y-j]=1+dist[x][y];
                                q.push({x-i, y-j});
                            }
                        }
                    }
                }
            }
            
        }
        
        if(dist[n-1][n-1]>=inf)return -1;
        return dist[n-1][n-1]; 
    }
    
};