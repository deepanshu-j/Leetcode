
class dsu{
    public:
    vector<int> parent, size;
    
    dsu(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=1;i<=n;++i) parent[i] = i, size[i] = 1;
    }
    
    int getParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = getParent(parent[u]);
    }
    
    void join(int u, int v){
        u = getParent(u), v = getParent(v);
        if(u==v) return;
        if(size[u] < size[v]) swap(u, v);
        size[u] += size[v];
        parent[v] = u;
    }
    
    bool isSameComponent(int u, int v){
        u = getParent(u), v = getParent(v);
        return u == v;
    }
    
};
class Solution {
public:

    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // one approach can be to find the cycle //
        // cycle will exist because for n nodes and n edges it must create a cycle
        // hence just find the edges which are in that cycle and return that last edge
        
        // cycle can be found using a dsu just like we do in an mst //
        int n = edges.size();
        dsu _dsu(n);
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            if(_dsu.isSameComponent(u, v)) return edge;
            _dsu.join(u, v);
        }
        
        return {};
    }
};