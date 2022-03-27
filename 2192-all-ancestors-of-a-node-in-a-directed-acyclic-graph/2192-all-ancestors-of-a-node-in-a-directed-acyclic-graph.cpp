class Solution {
public:
    
    set<int>* dfs(int src, vector<int> &vis, map<int, vector<int>> &prev, vector<set<int>*> &res){
        
        if(vis[src])return res[src];
        
        vis[src]=true;
        set<int>* this_ans = new set<int>();
                
        for(auto x: prev[src]){
            (*this_ans).insert(x);
           
            set<int>* ptr=dfs(x, vis, prev, res);
            for(auto itr=ptr->begin();itr!=ptr->end();++itr)
                this_ans->insert(*itr);
            
            // for(auto y:  (*)) (*this_ans).insert(y);
        }
        return res[src]=this_ans;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> prev; 
        vector<set<int>*> res(n);
        vector<vector<int>> ans(n);
        
        for(auto &edge: edges){
            prev[edge[1]].emplace_back(edge[0]);
        }
        
        vector<int> vis(n, 0);
        
        for(int i=0;i<n;++i){
            auto ptr = dfs(i, vis, prev, res);
            for(auto itr=ptr->begin();itr!=ptr->end();++itr)
                ans[i].emplace_back(*itr);
        }
        
        return ans;
    }
};