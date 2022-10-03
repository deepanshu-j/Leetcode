class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        
        int removed = 0;
        
        int n = neededTime.size();
        for(int i=0; i<n;){
            
            int j = i;
            int cur_sum = 0;
            int cur_mx  = neededTime[i];
            while(j<n and colors[j] == colors[i]){
                cur_sum += neededTime[j];
                cur_mx = max(cur_mx, neededTime[j]);
                ++j;
            }
            
            cur_sum -= cur_mx;
            
            removed += cur_sum;
            
            i = j;
        }
        
        return removed;

    }
};