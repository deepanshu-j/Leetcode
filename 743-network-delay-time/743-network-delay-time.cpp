#define pii  pair<int,int>
#define inf 0x3f3f3f3f
#define ff first
#define ss second
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // vector<int> vis(n+1,0);
        // for(int i=0;i<=n;++i)
        //     vis[i]=0;
        
        // single source all pair shortest path - Dijsktra //
        vector<int> dist(n+1, inf);
        vector<int> ans(n+1, inf);

        vector<vector<pii>> graph(n+1);
        
        for(auto &x: times){
            graph[x[0]].emplace_back(make_pair( x[2], x[1] ));
        }
        
        int source=k;
        
        dist[source]=0;
        ans[source]=0;
        priority_queue<pii, vector<pii>, greater<pii> > pq; // {dist_from_source, node}
        
        pq.push({0, source});
        
        while(!pq.empty()){
            auto tp=pq.top();
            pq.pop();
            
            int wt=tp.ff;            
            int u=tp.ss;
            for( auto v: graph[u] ){
                if(dist[u] + v.ff < dist[v.ss]){
                    dist[v.ss] = dist[u] + v.ff;
                    pq.push({dist[v.ss], v.ss});
                    ans[v.ss]=dist[v.ss]-dist[u]; // v.ff
                }
            }
        }
        
        int res=0;
        // return dist[2];
        for(int i=1;i<=n;++i){
            res=max(res, dist[i]);
        }
        
        if(res==inf)return -1;
        return res;
        
    }
};