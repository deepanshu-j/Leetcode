class Solution {
public:
    int memo[501];
    int dp(int n, int k, vector<int>& arr){
        if(n<0)return 0;
        
        
        if(memo[n]!=-1)return memo[n];
        
        int ans=0;
        int mx=arr[n];
        
        for(int i=0;i<k;++i){
            if(n-i>=0){
                mx=max(mx, arr[n-i]);
                int sub_ans = mx*(i+1) + dp(n-i-1, k, arr);
                ans = max(ans, sub_ans);        
            }
        }
        
        return memo[n]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        
        memset(memo, -1, sizeof memo);
        
        return dp(n-1, k, arr);
        
    }
};