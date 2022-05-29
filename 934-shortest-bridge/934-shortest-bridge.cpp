#define mkp make_pair
#define pii pair<int,int>
class Solution {
public:
    
    
    queue<pii> q; 
    int inf = 0x3f3f3f3f;
    pii null_pair = {-1, -1};
    int vis[101][101];
    int dist[101][101];

    vector<vector<int>> grid;
    int n;
    
    bool check(int i, int j){
        return (i>=0 and i<n and j>=0 and j<n);
    }
    
    void dfs(int i, int j){
        
        if(not check(i, j))
            return;
        
        if(grid[i][j] == 0 or vis[i][j])
            return;
        
        vis[i][j] = 1;
        
        q.push(mkp(i, j));
        dist[i][j] = 0;
        
        dfs(i+1, j);
        dfs(i-1, j);
        dfs(i, j-1);
        dfs(i, j+1);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        Solution::grid = grid;
        n = grid.size(); 
        memset(vis, 0, sizeof vis);
        bool flag=0;
        
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                dist[i][j]=inf;
        // memset(qvis, 0, sizeof qvis);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]){
                    dfs(i, j);
                    flag=1;
                    break;
                }
                if(flag)break;
            }
            if(flag)break;
        }

        // q -> [1,2,3,4,null]
        /// the process all these until you find null //
        // [null,5,6,7,8]
        // find null add a null if the q is not empty else break
        

        
        // cout<<"q.size():"<<q.size()<<'\n';
        
        int len = 0 ;
       
        
        dist[q.front().first][q.front().second] = 0;
        
        while(!q.empty()){

            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            
            for(int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                
                if(check(x, y) and !vis[x][y]) {
                    vis[x][y] = 1;
                    q.push({x, y});
                    dist[x][y] = min(dist[x][y], dist[i][j] + 1);
                }
            }
         
        }
            
         
        int ans = inf;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                // cout<<dist[i][j]<<" ";
                if(grid[i][j]==1 and dist[i][j] > 0)
                    ans = min(ans, dist[i][j]);
            }
            // cout<<"\n";
        }
        return ans-1;
    }
};