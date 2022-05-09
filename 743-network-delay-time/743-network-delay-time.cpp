#define pii pair<int,int> 
#define inf 0x3f3f3f3f
#define eb emplace_back
#define mkp make_pair
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int, vector<pii>> graph;
        for(auto &x: times)
            graph[x[0]].eb(mkp(x[1], x[2]));
        
        
        int src=k;
        
        int vis[n+1];
        for(int i=1;i<=n;++i)vis[i]=0;
        int dist[n+1];
        for(int i=1;i<=n;++i)dist[i]=inf;
        
        dist[src]=0;
        
        priority_queue<pii, vector<pii>, greater<pii>> pq; // {dist_from_src, node }
        
        pq.push(mkp(0, src));
        
        while(!pq.empty()){
            int start = pq.top().second;
            int dist_start = pq.top().first; // will be same as dist[start] //
            pq.pop();
            
            if(vis[start])continue;
            
            vis[start]=1;
            
            for(auto x: graph[start]){
                int v=x.first;
                int wt=x.second;
                if(dist_start+wt<dist[v]){
                    dist[v] = dist_start + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        // return dist[3];
        int ans=0;
        
        for(int i=1;i<=n;++i)
            ans=max(dist[i], ans);
        
        return (ans==inf)?-1:ans;
        
    }
};