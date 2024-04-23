class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 1) return {0};
        
        vector<set<int>> tree(n);
        vector<int> degree(n,0);
        for(auto e: edges){
            int u = e[0], v = e[1];
            tree[u].insert(v);
            tree[v].insert(u);
            degree[u]++; degree[v]++;
        }
        
        // find leaf nodes and start bfs //
        queue<int> q;
        for(int i=0;i<n;++i)
            if(degree[i] == 1){
                q.push(i);        
            }
        
        vector<int> ans;
        while(!q.empty()){
            int sz = q.size();
            ans.clear();
            while(sz--){
                int tp = q.front(); q.pop();
                ans.push_back(tp);
                for(auto adj: tree[tp]){
                    degree[adj]--;
                    if(degree[adj] == 1) q.push(adj);
                }
            }
        }
        
        return ans;
    }
};