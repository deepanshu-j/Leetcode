class Solution {
public:
    vector<vector<int>> adjList;
    int without_x[100005][26];
    string str;
    
    int dfs(int node, int x){
        
        if(without_x[node][x] != -1) return without_x[node][x];
        
        if(str[node] - 'a' == x){
            return without_x[node][x] = 0;
        }
    
        
        int ans = 0;
        for(auto adj: adjList[node]){
            int cur_x = str[node] - 'a';
            ans = max(ans, dfs(adj, cur_x));
        }
        return without_x[node][x] = ans+1;
    }
    
    int res = 0;
    void dfs_call(int node){
        
        // considering this node as the pivot //
        vector<int> child_answers;
        
        for(auto adj: adjList[node]){
            
            int cur_x = str[node] - 'a';
            child_answers.push_back( dfs(adj, cur_x) );
            dfs_call(adj);
            
        }
        
        sort(child_answers.begin(), child_answers.end(), greater<int>());
        
        if(child_answers.size() == 0){
            res = max(1, res);
        }
        else
        if(child_answers.size() == 1){
            
            int ans = 1 + child_answers[0];
            res = max(res, ans);
            
        }else
        if(child_answers.size()>1){
            int ans = 1 + child_answers[0] + child_answers[1];
            res = max(res, ans);
        }
        
    }
    
    int longestPath(vector<int>& parent, string s) {
        this->str = s;
        int n = parent.size();
        adjList.resize(n+1);
        
        for(int i=1;i<n;++i)
            adjList[parent[i]].push_back(i);
        
        memset(without_x, -1, sizeof without_x);
        
        int root = 0;
        dfs_call(root);
        
        return res;
    }
};