class Solution {
public:
    vector<int> cost;
    int n;
    int memo[1001];
    int dp(int i){
        if(i>=n)return 0;
        if(memo[i]!=-1)return memo[i];
        return memo[i] = cost[i] + min(dp(i+1), dp(i+2));
    }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        Solution::cost = cost;
        n = cost.size();
        memset(memo, -1, sizeof memo);
        return min(dp(0), dp(1));
    }
};