class Solution {
public:
    
    const int MOD = 1e9 + 7;
    int memo[1001][1001];
    int dp(int n, int k){
        
        // if(n==1){
        if(k<=0 or n==1)
            return (k==0);
        // }
        
        if(memo[n][k]!=-1)return memo[n][k];
        
        int ans = dp(n-1, k);
        if(k>0) ans = (ans%MOD + dp(n, k-1)%MOD)%MOD; 
        if(k-n>=0)
        ans = (MOD + ans - dp(n-1, k-n))%MOD; 
           
        return memo[n][k] = ans%MOD;
    }
    
    int kInversePairs(int n, int k) {
        
        memset(memo, -1, sizeof memo);
        
        int res =  dp(n, k);
        
        // for(int i=1;i<=20;i++){
        //     for(int j=1;j<20;++j){
        //         cout<<memo[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        
        return res;
    }
};