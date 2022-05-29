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
        
        if(!grid[i][j] or vis[i][j])return;
        
        vis[i][j] = 1;
        q.push(mkp(i, j));
        
        if(check(i+1, j) and grid[i+1][j] and !vis[i+1][j])dfs(i+1, j);
        if(check(i-1, j) and grid[i-1][j] and !vis[i-1][j])dfs(i-1, j);
        if(check(i, j-1) and grid[i][j-1] and !vis[i][j-1])dfs(i, j-1);
        if(check(i, j+1) and grid[i][j+1] and !vis[i][j+1])dfs(i, j+1);
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        Solution::grid = grid;
        n = grid.size(); 
        memset(vis, 0, sizeof vis);
        bool flag=0;
        
      for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            dist[i][j]=inf;


        
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
        
        q.push(null_pair);
        
        // q -> [1,2,3,4,null]
        /// the process all these until you find null //
        // [null,5,6,7,8]
        // find null add a null if the q is not empty else break
        
        // memset(dist, 0, sizeof dist);
      
        // cout<<"q.size():"<<q.size()<<'\n';
        
        int len = 0 ;
        int qvis[101][101];
        memset(qvis, 0, sizeof qvis);
        while(q.size()){
            
            while(!q.empty() and q.front()!=null_pair){
                
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                qvis[i][j]=1;
                
                // cout<<i<<" "<<j<<"\n";
                
                dist[i][j] = min(dist[i][j], len);
                
                if(check(i+1, j)  and !qvis[i+1][j])q.push(mkp(i+1, j)), qvis[i + 1][j] = 1;
                if(check(i-1, j)  and !qvis[i-1][j])q.push(mkp(i-1, j)), qvis[i - 1][j] = 1;
                if(check(i, j+1)  and !qvis[i][j+1])q.push(mkp(i, j+1)), qvis[i][j + 1] = 1;
                if(check(i, j-1)  and !qvis[i][j-1])q.push(mkp(i, j-1)), qvis[i][j - 1] = 1;

            }
            
            q.pop();
            len++;
            
            if(q.empty())break;
            else q.push(null_pair);
        }
        
        int ans = inf;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                // cout<<dist[i][j]<<" ";
                if(grid[i][j]==1 and vis[i][j]==0)
                    ans = min(ans, dist[i][j]);
            }
            // cout<<"\n";
        }
        return ans-1;
    }
};