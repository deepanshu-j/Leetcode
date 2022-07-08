class Solution {
public:
    const int inf = 1e8;
    vector<int> houses; 
    vector<vector<int>> cost; 
    int m, n, target;
    vector<vector<int>> p, e;
    int glo = inf;
    
    int memo[101][22][101];
    
    int dp(int i, int prev_color, int sub_arr_cnt){
        // base case //
        if(i==m){
            if(sub_arr_cnt==target)
                return 0;
            else 
                return inf;
        }
        
        int ans = inf;
        
        if(memo[i][prev_color][sub_arr_cnt]!=-1)return memo[i][prev_color][sub_arr_cnt];
        
            
       
        if(houses[i]==0){
            
            // try all color //
            for(int color = 1; color<=n; ++color){
                int this_cost = 0; 
                    
                this_cost += cost[i][color-1] + dp( i+1, color, sub_arr_cnt+(color!=prev_color) );
                
                ans = min(ans, this_cost);                
            }

        }else{
            int this_cost = 0; 
            int color = houses[i];
            this_cost += dp( i+1, color, sub_arr_cnt+(color!=prev_color) );

            ans = min(ans, this_cost);                
        }

        return memo[i][prev_color][sub_arr_cnt] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        Solution::houses = houses;
        Solution::cost = cost;
        Solution::m = m;
        Solution::n = n;
        Solution::target = target;
        
        p.resize(m, vector<int>(n, 0));
        e.resize(m, vector<int>(n, 0));

        memset(memo, -1, sizeof memo);
        
        for(int j=0;j<n;++j){
            p[0][j] = cost[0][j];
            for(int i=1;i<m;++i){
                p[i][j] += (p[i-1][j] + cost[i][j]);
            }
        }

        for(int j=0;j<n;++j){
            if(houses[0]==j+1)
            e[0][j] = cost[0][j];
            
            for(int i=1;i<m;++i){
                if(houses[i]==j+1) e[i][j] += cost[i][j];
                e[i][j] += e[i-1][j];
            }
        }
        
        // cout<<"Cost to color:\n";
        // for(int i=0;i<m;++i){
        //     for(int j=0;j<n;++j){
        //         cout<<p[i][j]<<" ";
        //     }cout<<"\n";
        // }
        
        //  cout<<"Extra Cost to color:\n";
        // for(int i=0;i<m;++i){
        //     for(int j=0;j<n;++j){
        //         cout<<e[i][j]<<" ";
        //     }cout<<"\n";
        // }
        
        int temp = dp(0, 21, 0);
        if(temp>=inf)return -1;
        return temp;
    }
};