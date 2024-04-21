class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        bool f = 0;
        
        vector<vector<int>> graph(n);
        for(auto &e: edges){
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> vis(n, 0);
        function<void(int)> dfs = [&](int node){
            if(vis[node]) return;
            vis[node] = 1;
            if(node == destination) f = 1;
            for(int& adj: graph[node]){
                if(vis[adj] == 0) dfs(adj);
            }
        };
        
        dfs(source);
        
        return f;
    }
};