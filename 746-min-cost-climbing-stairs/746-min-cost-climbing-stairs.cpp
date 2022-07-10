class Solution {
public:
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int nxt = 0, sec_nxt = 0 ; 
        for(int i=n-1;i>=0;--i){
            int cur = cost[i] + min(nxt, sec_nxt);
            sec_nxt = nxt;
            nxt = cur;
        }
        
        return min(nxt, sec_nxt);
    }
};