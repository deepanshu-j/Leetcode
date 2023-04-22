class Solution {
public:
    
    const static int sz =  1e6;
    vector<int> g[sz+1]; // stops to buses
    map<int, vector<int>> g2;
    
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source == target) return 0;
        
        int route_sz = routes.size();
        for(int i=0;i<route_sz;++i){
            int bustops = routes[i].size();
            for(int j=0;j<bustops;++j){
                int bustop = routes[i][j];
                g[bustop].push_back(i);
            }
        }
        
        // g2 // bustop -> [ bus1, bus2  ]
        const int inf = 1e9;
        int dp[501][501];
        vector<bool> is_source(501);
        vector<bool> is_destination(501);
        
        for(int i=0;i<501;++i) for(int j=0;j<501;++j) dp[i][j] = ((i==j)?0:inf);
        
        for(int i=0;i<sz+1;++i){ // i = stops
            
            
            for(int j=0;j<g[i].size();++j){ // j = bus
                
                if(i == source) is_source[g[i][j]] = 1; 
                if(i == target) is_destination[g[i][j]] = 1; 
                
                for(int k=j+1;k<g[i].size();++k){
                    int bus1 = g[i][j], bus2 = g[i][k];
                    dp[bus1][bus2] = dp[bus2][bus1] = 1;
                }
            }
        }
        
        
        
        for(auto x: g2[source])
            is_source[x] = 1;
        
        for(auto x: g2[target])
            is_destination[x] = 1;
        
        int ans = 1e9;
        // g2 is an undirected graph //
        
        int n = routes.size();
        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                    
                    if(is_source[i] and is_destination[j])
                        ans = min(ans, dp[i][j]);
                }
            }
        }
        
        if(ans == inf) return -1;
        
        return 1+ans;
    }
};