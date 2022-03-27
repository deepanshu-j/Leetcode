using vi = vector<int>;
class Solution {
public:
    
    int n, full, inf=1e9+7;
    vi bfs(int src, vector<vector<int>>& graph){
        // start bfs from src //
        n=graph.size();
        vi dist(n);
        
        dist[src]=0;
        queue<int> q;
        q.push(-1);
        q.push(src);
        
        int cnt=-1;
        
        vi vis(n, 0);
        
        while(!q.empty()){
            int tp=q.front();
            q.pop();
            
            if(tp==-1){
                ++cnt;
                
                if(!q.empty())
                q.push(-1);
                
                continue;
            }
            
            if(!vis[tp]){
                vis[tp]=true;
                dist[tp]=cnt;
            }
            
            
            for(auto x: graph[tp]){
                if(!vis[x])
                    q.push(x);
            }
            
        }
        return dist;
    }
    
    int memo[15][(1<<12)+10];
    int dp(int src, int mask, vector<vector<int>> &dist){
        if(mask==full){
            return 0;
        } 

        
        if(memo[src][mask]!=-1)return memo[src][mask];
        
        int res=inf;
        for(int i=0;i<n;++i){
            if(not(mask&(1<<i))){ // is ith bit unset //
                int new_mask = mask|(1<<i);
                res=min(res, dist[src][i] + dp(i, new_mask, dist));
            }
        }
        return memo[src][mask]=res;
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        // dist[u][v] //  shortest dist b/w node u and v //
        vector<vector<int>> dist;
        n=graph.size();
        
        for(int i=0;i<n;++i){
            vi sub = bfs(i, graph);
            dist.emplace_back(sub);
        }
        
        memset(memo, -1, sizeof memo);
        // return dist[0][4];
        
        for(int i=0;i<n;++i)
            full|=(1<<i);
        
        int res=inf, mask=0;
        for(int src=0;src<n;++src){
            res=min(res, dp(src, mask|(1<<src), dist));
        }
        return res;
    }
};