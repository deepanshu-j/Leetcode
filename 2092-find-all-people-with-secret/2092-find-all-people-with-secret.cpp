class DisjointSets {
	

  public:
    vector<int> parents;
	vector<int> sizes;
    
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	/** @return the "representative" node in x's component */
	int find(int x) {
		return parents[x] == x ? x : (parents[x] = find(parents[x]));
	}

	/** @return whether the merge changed connectivity */
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	/** @return whether x and y are in the same connected component */
	bool connected(int x, int y) { return find(x) == find(y); }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        DisjointSets dsu(n+1);
        
        map<int, vector<vector<int>>> layers;
        
        vector<int> fi{0, firstPerson};
        layers[0].push_back(fi);
        
        for(auto edge: meetings){
            int u = edge[0], v = edge[1], w = edge[2];
            vector<int> e{u, v};
            layers[w].push_back(e);
        }
        
        
        for(auto x: layers){
            
            set<int> vis;
            
            for(vector<int> y: x.second){
                int u = y[0], v = y[1];
                dsu.unite(u, v);
                vis.insert(u); 
                vis.insert(v);
            }
            
            for(auto node: vis){
                if(dsu.find(node) != dsu.find(0)){
                    dsu.parents[node] = node;
                    dsu.sizes[node] = 1;
                }
            }
        }
        
        vector<int> result;
        for(int i=0;i<=n;++i){
            if(dsu.find(i) == dsu.find(0)){
                result.emplace_back(i);
            }
        }
        
        return result;
    }
};