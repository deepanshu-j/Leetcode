class Solution {
public:
    int inf = 1e7;
    vector<vector<int>> cuboids;
    int memo[105][105][3];
    int dp(int i, int prev, int h_i){ // l<=b always, and h_i height index
        
        // cout<<"i:"<<i<<" , prev:"<<prev<<" , h_i:"<<h_i<<"\n";
        if(i==-1)return 0;
        
        int ans = -inf;
        if(memo[i][prev][h_i]!=-1)return memo[i][prev][h_i];
    
        int l = cuboids[prev][(h_i+1)%3], b = cuboids[prev][(h_i+2)%3];
        if(l>b)swap(l, b);
        
        // can we take it //
        if(cuboids[i][0]<=l and cuboids[i][1]<=b and cuboids[i][2]<=cuboids[prev][h_i]){
            ans = max(ans, cuboids[i][2]+dp(i-1, i, 2) );    
        }
        
        if(cuboids[i][1]<=l and cuboids[i][2]<=b and cuboids[i][0]<=cuboids[prev][h_i]){
            ans = max(ans, cuboids[i][0]+dp(i-1, i, 0) ); 
        }
        
        if(cuboids[i][0]<=l and cuboids[i][2]<=b and cuboids[i][1]<=cuboids[prev][h_i]){
            ans = max(ans, cuboids[i][1]+dp(i-1, i, 1) ); 
        }
        
        // dont take it //
        ans = max(ans, dp(i-1, prev, h_i));
        
        return memo[i][prev][h_i] = ans;
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        
        memset(memo, -1, sizeof memo);
        for(auto &x: cuboids)    sort(x.begin(), x.end());
        
        sort(cuboids.begin(), cuboids.end());
        
        // for(auto x: cuboids){
        //     cout<<x[0]<<" , "<<x[1]<<" , "<<x[2]<<"\n";
        // }
        int n = cuboids.size();
        cuboids.push_back(vector<int>({101, 101, 101}));
        Solution::cuboids = cuboids;
        // cout<<"n:"<<n<<"\n";
        return dp(n-1, n, 1);
    }
};