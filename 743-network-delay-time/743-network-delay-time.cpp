class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        int inf = 1e7;
        int dist[n+1];
        for(int i=0;i<=n;++i) dist[i] = inf;
        
        dist[k] = 0;
        
        for(int i=0;i<n;++i){
            for(auto &x: times){
                int u = x[0], v = x[1], w = x[2];
                dist[v] = min(dist[u] + w, dist[v]);
            }
        }
        
        
        int mx = 0;
        for(int i=1;i<=n;++i)
            mx = max(mx, dist[i]);  
        
        if(mx == inf)return -1;
        return mx;
    }
};