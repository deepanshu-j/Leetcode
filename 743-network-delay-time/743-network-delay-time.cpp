using pii = pair<int,int>;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // form adjList //
        vector<vector<pii>> adjList(n+1);
        for(auto &x: times){
            
            int u = x[0], v = x[1], w = x[2];
            adjList[u].push_back({w, v});
            
        }
        
        // dijkstra //
        const int inf = 1e7;
        int dist[n+1];
        for(int i=0;i<n+1;++i)dist[i] = inf;
        
        dist[k] = 0;
        
        multiset<pii> ms; // {weight, node} //
            
        ms.insert({0, k});
        
        while(!ms.empty()){
            
            
            // extract the smallest dist node from the source node //
            pii top = *ms.begin();  
            ms.erase(ms.begin());
            int cur = top.second;
            
            // update the dist of all the adjacent nodes of this cur //
            
            for(pii adj: adjList[cur]){
                
                int weight = adj.first, adj_node = adj.second; 
                if( dist[cur] + weight < dist[adj_node] ){
                    int new_dist =  dist[cur] + weight;
                    dist[adj_node] = min(dist[adj_node], new_dist); 
                    ms.insert({ new_dist, adj_node }); 
                }
                
            }
            
            
        }
        
        
        
        int mx = 0;
        for(int i=1;i<=n;++i)mx = max(mx, dist[i]);
        
        if(mx == inf)return -1;
        return mx;
        
        
    }
};