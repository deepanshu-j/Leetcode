#define rep(i,a,b) for(int i=a ; i<(b) ; ++i )
#define pb push_back
#define eb emplace_back
typedef pair<int,int> pii;
typedef vector<int> vi;

class Solution {
public:
    
    set<int> courses;
    unordered_map<int, vi> graph;
    
    bool cycleDetected=0;
    
    unordered_map<int, int> vis;
    unordered_map<int, int> onpath;
    
    void dfs(int node){
        
        if(vis[node]){
            if(onpath[node])
                cycleDetected=true;
            
            return;
        }
        
        vis[node]=1;
        onpath[node]++;
        
        for(auto x: graph[node]){
            dfs(x);
        }
        
        onpath[node]--;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for(auto &x: prerequisites){
            courses.insert(x[1]);
            courses.insert(x[0]);
            
            graph[x[1]].eb(x[0]);
        }
        
        for(auto &x: courses){
            
            onpath.clear();
            if(!vis[x])
                dfs(x);
            
            if(cycleDetected){
                return false;
            }
        }
        
        return !cycleDetected;
    }
};