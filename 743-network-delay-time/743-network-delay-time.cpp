#define rep(i,a,b) for(int i=a;i<b;++i)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        int inf = 0x3f3f3f3f;
        
        int dist[n+2];
        rep(i,0,n+1)dist[i]=inf;
        
        dist[k]=0;
        
        rep(j,0,n+2){
            for(auto &x: times){
                int u=x[0],v=x[1],w=x[2];
                // if(dist[v]<dist[u]+w)
                    // dist[v] = dist[u]+w
                dist[v]=min(dist[v], dist[u]+w);
            }
        }
        
        // rep(i,0,n+1)cout<<dist[i]<<" ";
        
        int mx=-1;
        rep(i,1,n+1)mx = max(mx, dist[i]);
        
        return ((mx==inf)?-1:mx);
    }
};