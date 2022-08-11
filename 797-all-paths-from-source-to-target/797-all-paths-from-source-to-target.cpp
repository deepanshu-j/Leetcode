class Solution {
public:
    vector<vector<int>> all_paths;
    vector<vector<int>> graph;
    vector<int> curr_path;
    
    int last_node;
    
    void dfs(int node){
        
        curr_path.emplace_back(node);
        
        if(node == last_node){
            all_paths.emplace_back(curr_path);
            curr_path.pop_back();
            return;
        }
        
        
        for(auto adj: graph[node])
            dfs(adj);
        
        curr_path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->graph = graph;
        this->last_node = graph.size()-1;
        
        dfs(0);
        return all_paths;
    }
};