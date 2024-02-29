class Solution {
public:
    
    using pii = pair<int,int>;
    vector<int> ans;
    vector<vector<int>> tree;
    set<pii> edgeMap;
    
    int dfs1(int node, int par){
        int sum = 0;
        for(int ch: tree[node]){
            if(ch == par) continue;
            sum += (dfs1(ch, node) + edgeMap.count({ch, node}));
        }
        
        return sum;
    }
    
    void dfs2(int node, int par){
        if(par != -1)
            ans[node] = ans[par] + edgeMap.count({par, node}) - edgeMap.count({node, par}) ;    
        
        for(int ch: tree[node]){
            if(ch == par) continue;
            dfs2(ch, node);
        }
    }
    
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        
        ans.resize(n, 0);
        tree.resize(n, vector<int>());
        
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
            edgeMap.insert({u, v});
        }
        
        
        int sum = dfs1(0, -1);
        ans[0] = sum;
        dfs2(0, -1);
        
        return ans;
    }
};