#define eb emplace_back
class Solution {
public:
    int n;
    bool cycleDetected=false;
    map<int, vector<int>> graph;
    set<int> nodes;
    unordered_map<int, int> vis;
    unordered_map<int, int> onpath;
    
    stack<int> stk;
    
    void dfs(int node){
        
        if(vis[node]){
            if(onpath[node])
                cycleDetected=true;
            return;    
        }
        
        vis[node]=1;
        onpath[node]=1;
        
        for(auto x: graph[node])
            dfs(x);
        
        stk.push(node);
        onpath[node]=0;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n=numCourses;
        for(auto &x: prerequisites){
            nodes.insert(x[0]);
            nodes.insert(x[1]);
            
            graph[x[1]].eb(x[0]);
        }
        
        for(auto &x:nodes){
            if(!vis[x])
                dfs(x);
            if(cycleDetected)return vector<int>();
        }
        
        vector<int> res;
        if(cycleDetected)return res;
        while(!stk.empty()){
            int top = stk.top();
            res.eb(top);
            stk.pop();
        }
        
        // now also add the ones which are not prerequite of anyone //
        for(int i=0;i<n;++i){
            if(!vis[i]){
                res.eb(i);
            }
        }
        
        return res;
        
    }
};