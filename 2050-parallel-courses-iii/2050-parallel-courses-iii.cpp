class Solution {
public:
    using pii = pair<int,int>;
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<int> in(n+1), out(n+1); //indegree, outdegree // 
        
        vector<vector<int>> g(n+1);
        for(auto x: relations){
            int u = x[0], v = x[1];
            
            out[u]++;
            in[v]++;
            
            g[u].push_back(v);
        }
        
        
        set<int> pq; // nodes with current indegree == 0 // 
        
        for(int node = 1; node<=n; ++node){
            if(in[node] == 0) pq.insert(node);
        }
        
        vector<int> ans(n+1), bias(n+1, 0);
        
        while(!pq.empty()){
            
            int node = *pq.begin();
            pq.erase(node);
            
            ans[node] = bias[node] + time[node-1];
            for(int adj: g[node]){
                in[adj]--;
                bias[adj] = max(bias[adj], ans[node]); 
                
                if(in[adj] == 0){
                    pq.insert(adj);
                }
            }
            
        }
        
        
        int mx = *max_element(ans.begin(), ans.end());
        return mx;
    }
};